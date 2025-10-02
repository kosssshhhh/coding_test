#include <bits/stdc++.h>
using namespace std;

int n, m, ret = 1e9, a[54][54];
vector<pair<int, int>> chicken, house;

int chicken_dist(vector<int> &v) {
  int ret = 0;
  for (int i = 0; i < house.size(); i++) {
    int mn = 1e9;
    for (int j = 0; j < v.size(); j++) {
      int dist = abs(house[i].first - chicken[v[j]].first) +
                 abs(house[i].second - chicken[v[j]].second);
      mn = min(mn, dist);
    }
    ret += mn;
  }

  return ret;
}

void go(int start, vector<int> &v) {
  if (v.size() == m) {
    ret = min(ret, chicken_dist(v));
    return;
  }

  for (int i = start + 1; i < chicken.size(); i++) {
    v.push_back(i);
    go(i, v);
    v.pop_back();
  }

  return;
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 1)
        house.push_back({i, j});
      else if (a[i][j] == 2)
        chicken.push_back({i, j});
    }
  }

  vector<int> v;

  go(-1, v);

  cout << ret;

  return 0;
}

// 치킨 거리가 가장 작아지는 M개 치킨집 고르기
// 재귀를 통한 완탐
//