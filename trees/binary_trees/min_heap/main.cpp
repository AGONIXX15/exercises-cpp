#include <iostream>

using std::cout, std::endl;

void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}

class MinHeap {
  int *arr;
  int capacity;
  int heap_size;

public:
  MinHeap(int capacity) : capacity(capacity) {
    heap_size = 0;
    arr = new int[capacity];
  }

  MinHeap(std::initializer_list<int> list) {
    heap_size = list.size();
    arr = new int[heap_size];
    capacity = heap_size * 2;
    int i = 0;
    for (int val : list) {
      arr[i++] = val;
    }
    buildHeap();
  }

  ~MinHeap() { delete[] arr; }

  int parent(int index) { return (index - 1) / 2; }
  int left(int index) { return index * 2 + 1; }
  int right(int index) { return index * 2 + 2; }

  void insertKey(int k) {
    if (heap_size == capacity) {
      cout << "\n OVERFLOW couldnt insert the key" << endl;
      return;
    }

    ++heap_size;
    int i = heap_size - 1;
    arr[i] = k;

    while (i != 0 && arr[parent(i)] > arr[i]) {
      swap(arr[parent(i)], arr[i]);
      i = parent(i);
    }
  }

  int getMin() {
    if (heap_size > 0) {
      return arr[0];
    }
    throw std::runtime_error("heap size is 0");
  }

  int extractMin() {
    if (heap_size == 0) {
      return arr[0];
    }

    int root = arr[0];
    heap_size--;
    arr[0] = arr[heap_size];
    MinHeapify(0);
    return root;
  }

  void MinHeapify(int index) {
    int l = left(index);
    int r = right(index);
    int smallest = index;
    if (l < heap_size && arr[l] < arr[smallest]) {
      smallest = l;
    }
    if (r < heap_size && arr[r] < arr[smallest]) {
      smallest = r;
    }

    if (smallest != index) {
      swap(arr[index], arr[smallest]);
      MinHeapify(smallest);
    }
  }

  void buildHeap() {
    for (int i = heap_size / 2 - 1; i >= 0; --i) {
      MinHeapify(i);
    }
  }

  void print() const {
    std::cout << "[";
    for (int i = 0; i < heap_size; i++) {
      std::cout << arr[i] << " ";
    }
    std::cout << "]" << endl;
  }
};

int main() {
  MinHeap heap = {6, 9, 0, 5, 3, 100, -5, 20};
  heap.print();
}
