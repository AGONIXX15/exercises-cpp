#include <iostream>
#include <memory>

template <typename T> struct Node {
  T value;
  std::shared_ptr<Node<T>> next;
  std::weak_ptr<Node<T>> prev;
  Node(T data) {
    value = data;
  }
};

// cl



template <typename T>
class LinkedList {
  
  std::shared_ptr<Node<T>> head;
  std::shared_ptr<Node<T>> tail;
public:
  LinkedList() {}

  void push_front(T data) {
    std::shared_ptr<Node<T>> node = std::make_shared<Node<T>>(Node(data));
    if (head == nullptr) {
      tail = node;
      head = node;
      return;
    }

    head->prev = node;
    node->next = head;
    head = node;
  }

  void reverse() {
  std::shared_ptr<Node<T>> curr = head;
  std::shared_ptr<Node<T>> new_head = nullptr;

  while (curr) {
    // guardar siguiente antes de tocar nada
    auto next = curr->next;

    // invertir punteros
    curr->next = curr->prev.lock();
    curr->prev = next;

    // avanzar
    new_head = curr;
    curr = next;
  }

  head = new_head;
}


  friend std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
    std::shared_ptr<Node<T>> current = list.head;
    while(current) {
      os << current->value << "->";
      current = current->next;
    }
    os << "nullptr";
    return os;
  }

};

int main() {
    LinkedList<int> list;
  for(size_t i = 0; i < 100; ++i) {
    list.push_front(i);
  }
  list.reverse();
  std::cout << list << '\n';
  return 0;
}
