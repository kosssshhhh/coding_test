#include <bits/stdc++.h>
using namespace std;

int n, a, b, ret;
vector<pair<int, int>> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back({a, b});
  }

  sort(v.begin(), v.end());

  int s = v[0].first, e = v[0].second;

  for (int i = 1; i < n; i++) {
    int from = v[i].first, to = v[i].second;

    if (from <= e && e < to) {
      e = to;
    }
    if (e < from) {
      ret += e - s;
      s = from, e = to;
    }
  }
  ret += e - s;

  cout << ret;
  return 0;
}