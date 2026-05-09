#include <bits/stdc++.h>

using namespace std;

size_t calculate_value(char character) {
  return character - 'A';
}

char rotate(size_t steps, char character) {
    character = character - 'A';
  return (character + steps) % 26 + 65;
}

size_t calc_sum(string& s) {
  size_t result = 0;
  for(auto character: s) {
    result += character - 'A';
  }
  return result;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  string s; cin >> s;

  string first_part = string(s.begin(), s.end() - s.size()/2);
  string second_part = string(s.begin() + s.size()/2, s.end());

  size_t first_sum = calc_sum(first_part);
  for(auto& character: first_part) {
    character = rotate(first_sum, character);
  }
  // cout << first_part << '\n';
  size_t second_sum = calc_sum(second_part);
  for(auto& character: second_part) {
    character = rotate(second_sum, character);
  }
  size_t n = first_part.size();
  for(size_t i = 0; i < n; ++i) {
    size_t steps = calculate_value(second_part[i]);
    first_part[i] = rotate(steps, first_part[i]);
  }
  cout << first_part << '\n';

  return 0;
}
