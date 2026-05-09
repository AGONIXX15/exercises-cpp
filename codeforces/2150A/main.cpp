#include <bits/stdc++.h>

using namespace std;
template <typename T>
class Node {
  T data;
  Node<T>* left;
  Node<T>* right;
  
  Node(T data): data(data), left(nullptr), right(nullptr) {}
};

template <typename T>
class TreeNode {
  Node<T>* root;
  TreeNode(Node<T>* root): root(root) {}
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  while(t--) {
    size_t n,m; cin >> n >> m;
    string s; cin >> s;
    vector<size_t> v(m);
    
    for(auto& val: v) {
      cin >> val;
    }
    
    
  }
  return 0;
}
