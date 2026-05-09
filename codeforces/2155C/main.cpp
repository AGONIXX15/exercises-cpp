#include <bits/stdc++.h>
#include <memory>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t modulo = 676767677;
  size_t t;
  cin >> t;
  while (t--) {
    size_t n;
    cin >> n;

    vector<int> v(n);
    for (auto &val : v)
      cin >> val;
    // wizards with cape to the right x2
    // wizards with the cape to the left x1
    // x2 = ai ... an where x2
    // x2 + 1 = a0
    // k + 1 - x1 for that position + right ones in that position = a1
    // 2 possibles
    // k + 1 - 1 + 0 = a1 OR k + 1 -0 + 1 = a1
    //

    // we dont know the first wizard if he has the cape to the left or to the
    // right so after we gotta asummed it so the possible values are that ones
    //
    if (v.size() == 1) {
      cout << "2\n";
      continue;
    }
    long long k = v[0] - 1; // total_x2 + 1 OR total_x2
                            //
                            // and i think the answer is always in {0,1,2}
    // so we just need to find out which of those possibles is

    long long first_posible = k;
    long long second_posible = k + 2;

    long long current_x2 = 0; // first position = 0 or 1
    long long current_x1 =
        0; // 0 or 1 but after the first position we calc that

    if (first_posible == v[1]) {
      current_x2 = 1;
    } else if (second_posible == v[1]) {
      current_x1 = 1;
    } else {
      cout << "0\n";
      continue;
    }
    bool flag = false;

    for (size_t i = 2; i < v.size(); ++i) {

      if (flag)
        break;
      long long first_posible = k + 1 - (current_x2 + 1) + current_x1;
      long long second_posible = k + 1 - current_x2 + (current_x1 + 1);
      if (first_posible == v[1]) {
        current_x2 = 1;
      } else if (second_posible == v[1]) {
        current_x1 = 1;
      } else {
        flag = true;
        cout << "0\n" << '\n';
      }
    }
    if (flag)
      continue;

    cout << "neither 1 or 2" << '\n';
  }

  return 0;
}
