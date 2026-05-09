#include <Persona.hpp>
#include <iostream>


Persona::Persona(std::string name, int age) {
  this->name = name;
  this->age = age;
}


std::ostream& operator<<(std::ostream& os, Persona const& p){
  os << "name: " << p.name << " age: " << p.age << std::endl;
  return os;
}
