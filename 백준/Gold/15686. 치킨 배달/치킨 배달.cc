#include <bits/stdc++.h>
using namespace std;

int n, m, ret = 1e9, a[54][54];
vector<pair<int, int>> chicken, _house;

int chicken_dist(vector<int> &v) {
  int ret = 0;

  for (int i = 0; i < _house.size(); i++) {
    int mn = 1e9;
    for (int j = 0; j < v.size(); j++) {
      int dist = abs(_house[i].first - chicken[v[j]].first) +
                 abs(_house[i].second - chicken[v[j]].second);

      mn = min(mn, dist);
    }
    ret += mn;
  }

  return ret;
}

void go(int a, vector<int> &b) {
  if (b.size() == m) {
    ret = min(ret, chicken_dist(b));
    return;
  }

  for (int i = a + 1; i < chicken.size(); i++) {
    b.push_back(i);
    go(i, b);
    b.pop_back();
  }

  return;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 1)
        _house.push_back({i, j});
      else if (a[i][j] == 2)
        chicken.push_back({i, j});
    }
  }

  vector<int> b;

  go(-1, b);

  cout << ret;

  return 0;
}