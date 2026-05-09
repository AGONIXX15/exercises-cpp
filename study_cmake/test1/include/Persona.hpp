#pragma once
#include <format>
#include <string>

class Persona {
  std::string name;
  size_t age;

public:
  Persona(std::string, size_t);

  std::string get_name() const;

  size_t get_age() const;
};

template <>
struct std::formatter<Persona> : std::formatter<std::string> {
  auto format(const Persona& p, auto& ctx) const {
    std::string s = std::format("Persona(name={}, age={})", p.get_name(), p.get_age());
    return std::formatter<std::string>::format(s, ctx);
  }

};
