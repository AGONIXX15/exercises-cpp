#include <bits/stdc++.h>

using namespace std;

using Graph = unordered_map<char, unordered_map<char, float>>;
using Path = unordered_map<char, char>;
pair<float,Path> djikstra(Graph graph, char start_node, char finish_node) {
  unordered_set<char> visited;
  unordered_map<char, float> distances;
  Path p;
  for (auto [key, value] : graph) {
    distances.emplace(key, 1e5);
  }

  distances.emplace(start_node, 0);
  priority_queue<pair<float, char>> pq;

  pq.push(make_pair(0, start_node));

  while (!pq.empty()) {

    auto [current_distance, node] = pq.top();
    pq.pop();

    for (auto [neighboor, distance] : graph[node]) {
      float new_distance = current_distance + distance;
      if (new_distance < distances.at(neighboor)) {
        distances[neighboor] = new_distance;
        p[neighboor] = node;
        pq.push(make_pair(new_distance, neighboor));
      }
    }
  }

  return {distances[finish_node], p};
}

template <typename T, typename K>
ostream& operator<<(ostream& os, const unordered_map<T,K>& v) {
  for(auto key_value: v) {
    os << "key: " << key_value.first << " value: " << key_value.second << '\n';
  }
  return os;
}

int main() {
  unordered_map<char, unordered_map<char, float>> graph = {
      {'A', {{'B', 1.5}, {'C', 2.0}}},
      {'B', {{'C', 1.0}, {'D', 2.5}}},
      {'C', {{'D', 1.2}}},
      {'D', {}}};

  auto [distance, path] = djikstra(graph, 'A', 'D');
  cout << path << '\n';

  auto current_node = 'D';
  for(auto v = path.find(current_node); v != path.end() && v->first != 'A' ; v = path.find(v->second)) {
    cout << v->first << '\n';
  }
  // for(auto key_value: path) {
  //   cout << "key:" << key_value.first << " value: " << key_value.second << '\n';
  // }

  return 0;
}
