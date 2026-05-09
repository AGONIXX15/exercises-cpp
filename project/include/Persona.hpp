#pragma once
#include <string>

class Persona {
  std::string name;
  int age;

public:
  Persona(std::string, int);

  friend std::ostream& operator<<(std::ostream&, const Persona&);
};
