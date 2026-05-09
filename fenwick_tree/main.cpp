#include <bits/stdc++.h>

using namespace std;

struct BitTree {

  vector<int> bits;

  BitTree(size_t n) {

    bits.assign(n+1,0);
  }

  BitTree(const vector<int>& a) : BitTree(a.size()) {
        for (int i = 0; i < (int)a.size(); i++)
            update(i + 1, a[i]);
    }


  int sum(int id) {
    int ans = 0;
    while(id > 0) {
      ans += bits[id];
      id -= id & -id;
    }

    return ans;
  }

  void update(int id, int value) {
    while(id < bits.size()) {
      bits[id] += value;
      id += id & -id;
    }
  }



  int query(int l, int r) {
    return sum(r)-sum(l-1);
  }
  
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  vector<int> v = {1,2,3,4,5};
  BitTree t = v;

  cout << t.sum(5) << '\n';


  return 0;
}
