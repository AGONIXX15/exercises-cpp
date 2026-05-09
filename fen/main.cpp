#include <bits/stdc++.h>



using namespace std;


struct Fenwick {
  int n; 
  vector<int> bit;
  Fenwick(vector<int>& v): n(v.size()), bit(n+1,0) {
    for(int i = 1; i <= n; i++) {
      bit[i] += v[i-1];
      int parent = i + (i & -i);
      if(parent <= n)
        bit[parent] += bit[i];
    }
  }

  void update(int i, long long v) {
    for(; i <= n; i += i & -i) {
      bit[i] += v;
    }
  }


  int sum(int r) {
    if(r < 0) throw logic_error("the fenwick tree starts at 1");
    if(r > n) throw logic_error("r cant be greater than the size of the tree");
    int val = 0;
    for(int i = r; i > 0; i -= (i & -i)) {
      val += bit[i];
    }
    return val;
  }

  int query(int l, int r) {
    if(l > r) throw logic_error("lower limit can be greater than the greater limit");
    return sum(r) - sum(l-1);
  }

};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  vector<int> v = {1,2,3,4,5};
  Fenwick f = v;

  cout << f.query(0,5) << '\n';

}
