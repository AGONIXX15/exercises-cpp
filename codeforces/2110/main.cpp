#include <bits/stdc++.h>


using namespace std;

int main() {
  
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::string line;
  for(int i = 0; i < n; ++i) {
    std::cin >> line;
    // verificar
    bool flag = false;
    int balance = 0;
  for(int i = 0; i < line.size(); ++i){
       if(line[i] == '(')balance += 1;
      else balance -=1;

      if(balance == 0 && i != line.size()-1){
        flag = true;
        break;
      }
    }
    cout << ((flag) ? "yes": "no") << endl;
  }
}
