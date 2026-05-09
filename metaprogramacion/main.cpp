#include <iostream>
#include <string>
#include <concepts>
#include <vector>

template<long long N>
struct Factorial {
  long long static constexpr value = N * Factorial<N-1>::value;
};

template <>
struct Factorial<0LL> {
  static constexpr long long value = 1LL;
};

struct nullopt_t {
  explicit nullopt_t() = default;
};

inline constexpr nullopt_t nullopt{};

template <typename T>
class Optional {
  bool has_value;
  alignas(T) unsigned char storage[sizeof(T)];

  T* ptr() {
    return reinterpret_cast<T*>(storage);
  }
  const T* ptr() const {
    return reinterpret_cast<const T*>(storage);
  }
  public:
  Optional(nullopt_t): has_value(false) {}

  Optional(const T& v) {
    new (storage) T(v);
    has_value = true;
  }
  ~Optional() {
    reset();
  }

  T& value() {
    if(!has_value) {
      throw std::runtime_error("No value");
    }
    return *ptr();
  }
  const T& value() const {
    if(!has_value) {
      throw std::runtime_error("No value");
    }
    return *ptr();
  }

  void reset() {
    if(has_value) {
      ptr()->~T();
      has_value = false;
    }
  }

  bool hasValue() {
    return has_value;
  }

  template<typename... Args>
  void emplace(Args&&... args) {
    reset();
    new (storage) T(std::forward<Args>(args)...);
    has_value = true;
  }
};
template <typename T>
concept esNumero = std::is_same_v<T,int> ||
  std::is_same_v<T,float> || std::is_same_v<T, long long> ||
  std::is_same_v<T,double>;

template <typename T>
concept canAdd = requires(T a, T b) {
{a + b} -> std::convertible_to<T>;
};
template <canAdd A>
A sum(A a, A b) {
  return a + b;
}


// template <typename T>
// struct convertible_to_bool;


// struct convertible_to_bool<1> {
//   static constexpr bool value = true;
// };

// struct convertible_to_bool<0> {
//   static constexpr bool value = false;
// };

int main() {
    
  Optional<int> a = nullopt;
  a = nullopt;
  std::cout << "gabriela es una bitch" << '\n';

    // std::cout << "tiene valor a y es: " << a.value() << '\n';
  // if(a.hasValue()) {
  // } else {
  //   std::cout << "a no tiene ningun valor" << '\n';
  // }

  std::cout << Factorial<10>::value << std::endl;
  int x;
  if constexpr (std::is_same<decltype(x), int>::value) {
    std::cout << "es un int" << '\n';
  } else {
    std::cout << "es otro tipo" << '\n';
  }
  return 0;
}
