#include <bits/stdc++.h>
using namespace std;

int N, temp1, temp2, dp[20];
vector<pair<int, int>> v;

int go(int idx) {
  if (idx >= N) return 0;

  int &ret = dp[idx];
  if (ret != -1) return ret;

  if (idx + v[idx].first <= N) {
    ret = max(ret, go(idx + v[idx].first) + v[idx].second);
  }

  ret = max(ret, go(idx + 1));

  return ret;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> temp1 >> temp2;
    v.push_back({temp1, temp2});
  }

  memset(dp, -1, sizeof(dp));

  cout << go(0);

  return 0;
}