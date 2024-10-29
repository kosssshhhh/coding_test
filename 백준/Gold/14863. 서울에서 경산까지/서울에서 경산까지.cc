#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
ll dp[104][100004];  // 백만 아니고
vector<pair<int, int>> walk_v, bike_v;

ll go(int here, int t) {
  if (t > k) return -1e9;
  if (here == n) {
    return 0;
  }
  ll &ret = dp[here][t];
  if (ret != -1) return ret;
  ret = -987654321;

  ret = max(ret, go(here + 1, t + walk_v[here].first) + walk_v[here].second);
  ret = max(ret, go(here + 1, t + bike_v[here].first) + bike_v[here].second);

  return ret;
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    walk_v.push_back({a, b});
    bike_v.push_back({c, d});
  }

  memset(dp, -1, sizeof(dp));

  cout << go(0, 0);
  return 0;
}