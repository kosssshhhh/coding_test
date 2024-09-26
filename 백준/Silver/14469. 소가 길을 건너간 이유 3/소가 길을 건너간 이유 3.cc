#include <bits/stdc++.h>
using namespace std;

int n, t;

int main() {
  cin >> n;
  vector<pair<int, int>> v(n);
  // 도착 시간, 검문 시간
  for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

  sort(v.begin(), v.end());

  for (pair<int, int> a : v) {
    if (t <= a.first) {
      t = a.first + a.second;
    } else {
      t += a.second;
    }
  }

  cout << t;

  return 0;
}