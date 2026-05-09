#include <iostream>
#include <memory>


class Enemy {
public:

  virtual void attack() = 0;

};


class Goblin: public Enemy {
  
  void attack() override {
    std::cout << "Goblin attacks\n";
  }
};


class Dragon: public Enemy {
  
  void attack() override {
    std::cout << "Dragon attacks\n";
  }
};

int main(void) {
  Enemy* goblin = new Goblin();
  Enemy* dragon = new Dragon();

  Enemy* e = dynamic_cast<Enemy*>(new Goblin());

  e->attack();
  goblin->attack();
  dragon->attack();
  return 0;
}
