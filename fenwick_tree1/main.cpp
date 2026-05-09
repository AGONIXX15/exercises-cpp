#include <iostream>
#include <vector>


class FenwickTree {
  private:
    std::vector<int> elements;

  void build(std::vector<int>& v) {
    elements = v;

    
    for(size_t i = 0; i < v.size(); ++i) {
      int parent = i | (i+1);
      if(parent < v.size()) {
        elements[parent] += elements[i];
      }
    }

  }

public:
  FenwickTree(std::vector<int>& v) {
    build(v);
  }

  int sum(int r) {
    int result = 0;
    for(; r >= 0; r = (r & (r+1))-1) {
        result += elements[r];
    }
    return result;
  }

};

int main() {
  std::vector<int> v = {1,2,3,4,5};
  FenwickTree ft = v;

  std::cout << ft.sum(2);
}
