#include <bits/stdc++.h>

using namespace std;

template <typename T> void print_vector(const vector<T> &v) {
  for (auto val : v) {
    cout << val << " ";
  }
  cout << '\n';
}
// template <typename T> void print_map(const unordered_map<T, vector<T>> &dct) {
//   cout << "{" << '\n';
//   for (auto p : dct) {
//     cout << p.first << ":";
//     print_vector(p.second);
//   }
//   cout << "}\n";
// }
//
struct Compare {
  bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
    return a.first > b.first;
  }
};

class Solution {

public:
  static bool cmp(const pair<int,int>& a, const pair<int, int>& b) {
    return a.first < b.first;
  }
  Solution() = default;
  vector<int> maxSubsequence(vector<int> &nums, int k) {
    // easy we can use a max heap an pop the k elements
    // no sirvio el heap pq lo necesitaba en orden de la subsequencia pero en si
    // seria una buena solucion hay que cambiar el approach creo que
    // programacion dinamica olviden dp si nos pidiera solo la solucion estaria
    // bien pero nos pide devolver los numeros que tomamos entonces la mejor
    // opcion seria un hashmap para guardar clave, valor o ya lo veran
    // value: [indexes]
    // ptmr necesito el hashmap para compararlos
    unordered_map<int,queue<int>> dct;
    for (int i = 0; i < nums.size(); ++i) {
      dct[nums[i]].push(i);
    }

    priority_queue<int, vector<int>, less<int>> q(nums.begin(), nums.end());

    vector<int> sol(k, 0);
    // sortear valores
    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
    while (k--) {
      pq.push(make_pair(dct[q.top()].front(), q.top()));
      q.pop();
    }
    size_t index = 0;
    while(!pq.empty()) {
      sol[index++] = pq.top().second;
      pq.pop();
    }
    return sol;
  }
};

int main() {
  Solution sol;
  vector<int> v = {-1, -2, 3, 4};
  print_vector(sol.maxSubsequence(v, 3));

  return 0;
}
