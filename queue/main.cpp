#include <iostream>

template <typename T> class Node {
public:
  Node *back = nullptr;
  Node *next = nullptr;
  T value;
  Node(T value) : value(value) {};
};

template <typename T> class DoubleLinkedList {

  Node<T> *head = nullptr;
  Node<T> *tail = nullptr;

public:
  DoubleLinkedList<T>() {}

  ~DoubleLinkedList<T>() {
    Node<T> *curr = head;
    while (curr != nullptr) {
      Node<T> *temp = curr;
      curr = curr->next;
      delete temp;
    }
  }

  void push_back(T value) {
    Node<T> *new_node = new Node<T>(value);
    if (head == nullptr) {
      head = new_node;
      tail = new_node;
      return;
    }
    tail->next = new_node;
    new_node->back = tail;
    tail = new_node;
  }

  void push_front(T value) {
    Node<T> *new_node = new Node<T>(value);
    if (tail == nullptr) {
      head = new_node;
      tail = new_node;
      return;
    }
    head->back = new_node;
    new_node->next = head;
    head = new_node;
  }

  void pop_back() {
    if (tail == nullptr) {
      return;
    }
    Node<T> *temp = tail;
    tail = tail->back;
    if (tail == nullptr) {
      head = nullptr;
    } else {
      tail->next = nullptr;
    }
    delete temp;
  }

  T peek_back() {
    if (tail == nullptr) {
      throw std::runtime_error("no hay elementos");
    }
    return tail->value;
  }

  void pop_front() {

    if (head == nullptr) {
      return;
    }
    Node<T> *temp = head;
    head = head->next;
    if (head == nullptr) {
      tail = nullptr;
    } else {
      head->back = nullptr;
    }
    delete temp;
  }

  T peek_front() {
    if (head == nullptr) {
      throw std::runtime_error("no hay elementos");
    }
    return head->value;
  }
};

template <typename T> class Queue {
private:
  DoubleLinkedList<T> dl;

public:
  Queue<T>(){};

  T peek() { return dl.peek_front(); }

  void pop() { dl.pop_front(); }

  void push(T value) { dl.push_back(value); }
};

template <typename T> class Stack {
private:
  DoubleLinkedList<T> dl;

public:
  Stack<T>() {}

  T peek() { return dl.peek_back(); }

  void pop() { dl.pop_back(); }

  void push(T value) { dl.push_back(value); }
};

int main() {
  Stack<int> s;
  s.push(5);
  s.push(10);
  s.push(15);
  std::cout << s.peek() << std::endl;
  s.pop();
  std::cout << s.peek() << std::endl;
  s.pop();
  std::cout << s.peek() << std::endl;
  s.pop();
}
