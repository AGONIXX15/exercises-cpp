#include <iostream>

template <typename T> class Node {

  Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}

  int get_height(Node<T> *n) {
    if (n == nullptr)
      return 0;
    return n->height;
  }

  int get_bf(Node *n) {
    return n ? get_height(n->left) - get_height(n->right) : 0;
  }

  Node<T> *right_rotate(Node<T> *root) {
    // x < root && t2 > x && t2 < root
    // t2
    Node<T> *x = root->left;

    Node<T>* t2 = x->right;

    x->right = root;
    root->left = t2;

    root->height = std::max(get_height(root->left), get_height(root->right)) + 1;

    x->height = std::max(get_height(x->left), get_height(x->right)) + 1;
    return x;
  }

  Node<T>* left_rotate(Node<T>* root) {
    // x > root && t2 < x && t2 > root
    Node<T>* x = root->right;

    Node<T>* t2 = x->left;

    x->left = root;
    root->right = t2;
    
    root->height = std::max(get_height(root->left), get_height(root->right)) + 1;
    x->height = std::max(get_height(x->left), get_height(x->right)) + 1;

    return x;
  }

public:
  T key;
  Node *left;
  Node *right;
  int height;
  Node<T>* insert(Node<T>* root, T key) {
    
    if(root == nullptr) {
      return new Node<T>(key);
    } else if(key < root->key) {
      root->left = insert(root->left, key);
    } else if(key > root->key) {
      root->right = insert(root->right, key);
    } else {
      return root;
    }
    
    root->height = std::max(get_height(root->left), get_height(root->right)) +1;

    int balance = get_bf(root);

    if(balance > 1 && key < root->left->key) {
      return right_rotate(root);
    }

    if(balance < -1 && key > root->right->key) {
      return left_rotate(root);
    }
    // LR
    if(balance > 1 && key > root->right->key) {
      root->left = left_rotate(root->left);
      return right_rotate(root);
    }

    if(balance < -1 && key < root->left->key) {
      root->right = right_rotate(root->right);
      return left_rotate(root);
    }
    return root;
  }

  void print_preorder(Node<T>* root) {
    if(root == nullptr) return;
    std::cout << root->key << " ";
    print_preorder(root->left);
    print_preorder(root->right);
  }

  void print_inorder(Node<T>* root) {
    if(root == nullptr) return;
    print_inorder(root->left);
    std::cout << root->key << " ";
    print_inorder(root->right);
  }
  
};


template <typename T> class AvlTree {

public:

  Node<T>* root = nullptr;
  AvlTree<T>(){}


  void insert(T key) {
    root = root->insert(root, key);
  }

  void print_preorder() {
    root->print_preorder(root);
  std::cout << std::endl;
  }

  void print_inorder() {
    root->print_inorder(root);
    std::cout << std::endl;
  }
};


int main() {
  AvlTree<int> v;

  v.insert(1);
  v.insert(-1);
  v.insert(2);
  // 1 -1 2
  // left nodo right
  // nodo left right
v.insert(3);
}
