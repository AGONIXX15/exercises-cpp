#include <bits/stdc++.h>
#include <vector>

using namespace std;
using ll = long long;

unordered_set<int> primes;
bool is_prime[301];

template <typename T> ostream &operator<<(ostream &os, vector<T> &v) {
  os << "[";
  for (int i = 0; i < v.size(); ++i) {
    os << v[i] << (i == v.size() - 1 ? "" : ", ");
  }
  os << "]";
  return os;
}

// (nloglogn)
void crib(int n) {
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      primes.insert(i);
      for (int j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

// void shift_right(vector<int>& v) {
//   // index,value
//   vector<pair<int,int>> ans;
//   for(int i = 0; i < v.size(); ++i) {
//     int new_pos = (i + 1) % v.size();
//     int value = v[i];
//   }
// }
//
// vector<vector<int>> sol;
// void backtracking(int i, int cnt, vector<vector<int>> &triplets,
//                   unordered_map<int, int> &dct, vector<int> &ans, int
//                   n,vector<int>& v) {
//   if(i >= triplets.size()) return;
//   if (cnt == n) {
//     sol.push_back(ans);
//     return;
//   }
//   if(cnt == 0) {
//     ans.push_back(triplets[i][0]);
//     ans.push_back(triplets[i][1]);
//     ans.push_back(triplets[i][2]);

//     backtracking(i+1,cnt+1,triplets,dct,ans,n,v);
//     ans.pop_back();
//     ans.pop_back();
//     ans.pop_back();
//   }

//   vector<int> t = triplets[i];
//   // por cada indice en el que voy si es posible el append hago el
//   backtracking for (int j = i + 1; j < v.size(); ++j) {
//     if(t[2] == triplets[j][0]) {

//     }
//   }
// }

ll min_value(vector<int> &ans) {
  ll sum = 0;
  ll f = 0;
  for (int i = 0; i < ans.size(); ++i) {
    sum += ans[i];
    f += ans[i] * (i + 1);
  }
  // sum = 1*a[1] + 1*a[2] ... + 1*a[n]
  // f(0) = 1*a[1] + 2*a[2] ... + n*a[n] + sum;
  // f(0) = 2*a[1] + 3*a[2] .... + 1*a[n];
  //
  // f(1) = 1*a[n] + 2*a[1] + 3*a[2] + .... n*a[n-1]
  // f(1) = f(1-1) - n*a[n]
  ll best = f;
  
  
  int n = ans.size();
  for (int i = 0; i < ans.size() - 1; ++i) {
    f = f + sum - ans[n - 1 - i] * n;
    best = min(best, f);
  }
  return best;
}
vector<vector<int>> sol;
ll best = 1e7;
using Map = unordered_map<int, int>;
void backtracking(vector<int> &v, vector<int> &ans, Map &dct,
                  vector<vector<vector<int>>> &graph) {
  int m = ans.size();
  if (m == v.size()) {
    if (is_prime[ans[m - 1] + ans[m - 2] + ans[0]] &&
        is_prime[ans[m - 1] + ans[0] + ans[1]])
      best = min(best, min_value(ans));
    return;
  }

  if (m >= 2) {
    int u = ans[m - 2];
    int v1 = ans[m - 1];
    for (auto w : graph[u][v1]) {
      if (dct[w] == 0)
        continue;

      ans.push_back(w);
      dct[w]--;
      backtracking(v, ans, dct, graph);
      dct[w]++;
      ans.pop_back();
    }
  } else {
    for (auto &[val, count] : dct) {
      if (count == 0)
        continue;
      ans.push_back(val);
      count--;
      backtracking(v, ans, dct, graph);
      count++;
      ans.pop_back();
    }
    return;
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  memset(is_prime, 1, sizeof(is_prime));
  crib(300);
  int t;
  cin >> t;
  while (t--) {
    best = 1e7;
    int n;
    cin >> n;
    sol = {};
    vector<int> v(n);
    Map dct;
    for (auto &val : v) {
      cin >> val;
      dct[val]++;
    }

    vector<vector<vector<int>>> graph(301, vector<vector<int>>(301));
    for (auto &[key1, value1] : dct) {
      for (auto &[key2, value2] : dct) {
        for (auto &[key3, value3] : dct) {
          if (is_prime[key1 + key2 + key3]) {
            graph[key1][key2].push_back(key3);
          }
        }
      }
    }
    vector<int> ans;
    backtracking(v, ans, dct, graph);

    if(best == 1e7) {
      cout << "impossible\n";
      continue;
    }
    cout << best << '\n';

    // (value, count)
    // vector<int> ans;
    // backtracking(v,ans,dct);
    // if(sol.size() == 0) {
    //   cout << "impossible\n";
    //   continue;
    // }

    // ll min_weight = 1e7;
    // for(int i = 0; i < sol.size(); ++i)  {
    //   int offset = 0;
    //   for(int j = 0; j < sol[i].size(); ++j) {
    //     ll weight = 0;
    //     for(int k = 0; k < sol[i].size(); ++k) {
    //       weight += k * sol[i][(k + offset) % n];
    //     }
    //     min_weight = min(min_weight, weight);
    //     offset = (offset - 1 + n) % n;
    //   }
    // }
    // cout << min_weight << '\n';
  }
  return 0;
}
