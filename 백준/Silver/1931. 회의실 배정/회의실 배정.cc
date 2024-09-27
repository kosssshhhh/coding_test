#include <bits/stdc++.h>
using namespace std;

int n, l, r, ret = 1;

int main() {
  cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].second >> v[i].first;
  }

  sort(v.begin(), v.end());

  l = v[0].second;
  r = v[0].first;

  for (int i = 1; i < n; i++) {
    if (r <= v[i].second) {
      l = v[i].second;
      r = v[i].first;
      ret++;
    }
  }

  cout << ret;

  return 0;
}