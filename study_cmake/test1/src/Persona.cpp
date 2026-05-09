#include "Persona.hpp"
#include <string>

Persona::Persona(std::string name, size_t age) : name(std::move(name)), age(age) {}


std::string Persona::get_name() const {
  return name;
}

size_t Persona::get_age() const {
  return age;
}
