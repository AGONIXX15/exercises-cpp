#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class MaxHeap {

  int *array;
  size_t heap_cap;
  size_t heap_size;

public:
  MaxHeap(size_t heap_cap) {
    array = new int[heap_cap];
    for (int i = 0; i < heap_cap; ++i) {
      array[i] = -1;
    }
    heap_size = 0;
    this->heap_cap = heap_cap;
  }

  ~MaxHeap() { delete[] array; }

  int left(int index) { return index * 2 + 1; }
  int right(int index) { return index * 2 + 2; }
  int parent(int index) { return (index - 1) / 2; }

  void copy_values(vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
      array[i] = v[i];
      heap_size++;
    }
  }

  void heapify(int index) {
    int largest = index;
    int l = left(index);
    int r = right(index);
    if (l < heap_size && array[l] > array[largest]) {
      largest = l;
    }

    if (r < heap_size && array[r] > array[largest]) {
      largest = r;
    }

    if (largest != index) {
      swap(array[index], array[largest]);
      heapify(largest);
    }
  }

  void insert(int k) {
    if (heap_size == heap_cap) {
      throw runtime_error("cannot be inserted the heap cap is full");
      return;
    }
    array[heap_size] = k;
    int i = heap_size;
    heap_size++;
    while (i != 0 && array[parent(i)] < array[i]) {
      swap(array[parent(i)], array[i]);
      i = parent(i);
    }
  }

  void increaseKey(int i, int new_val){
    array[i] = new_val;
    while(i != 0 && array[parent(i)] < array[i]){
      swap(array[parent(i)], array[i]);
      i = parent(i);
    }
  }

  void deleteKey(int i){
    increaseKey(i, INT_MAX);
    extractMax();
  }

  int getMax() {
    if (heap_size > 0) {
      return array[0];
    }
    throw runtime_error("there is no more items");
  }

  int extractMax(){
    if(heap_size == 0){
      return INT_MIN;
    }
    if(heap_size == 1){
      --heap_size;
      return array[0];
    }

    int root = array[0];
    array[0] = array[heap_size-1];
    --heap_size;
    heapify(0);
    return root;
  }

  static MaxHeap buildHeap(vector<int> &v) {
    MaxHeap mh(v.size() * 2);
    mh.copy_values(v);
    for (int i = mh.heap_size / 2 - 1; i >= 0; --i) {
      mh.heapify(i);
    }
    return mh;
  }

  friend std::ostream &operator<<(std::ostream &os, const MaxHeap &mh) {
    os << '[';
    for (int i = 0; i < mh.heap_size; ++i) {
      os << mh.array[i] << ' ';
    }
    os << "]\n";
    return os;
  }
};

int main() {
  vector<int> v = {1, 2, 3, 4, 5};
  MaxHeap mh = MaxHeap::buildHeap(v);
  mh.insert(100);
  mh.increaseKey(0,1000);
  cout << mh << endl;
}
