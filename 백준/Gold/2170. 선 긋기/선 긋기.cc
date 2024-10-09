#include <bits/stdc++.h>
using namespace std;

int n, from, to, ret;
vector<pair<int, int>> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> from >> to;
    v.push_back({from, to});
  }
  sort(v.begin(), v.end());

  from = v[0].first;
  to = v[0].second;

  for (int i = 1; i < v.size(); i++) {
    if (to > v[i].second) continue;

    if (to > v[i].first) {
      to = v[i].second;
    } else {
      ret += to - from;
      from = v[i].first;
      to = v[i].second;
    }
  }
  ret += to - from;
  cout << ret;
  return 0;
}