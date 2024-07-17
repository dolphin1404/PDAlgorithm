#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}
*/

int main() {
  int N;
  cin >> N;
  int a, b;
  vector<pair<int, int>> v;

  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    v.push_back({a,b});
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < N; i++) {
    cout << v[i].first << " " << v[i].second << endl;
  }
}