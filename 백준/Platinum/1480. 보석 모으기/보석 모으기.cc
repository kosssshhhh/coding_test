#include <bits/stdc++.h>
using namespace std;

int n, m, c, a[24], pack[24];
int dp[24][1 << 14][24];

int go(int here, int y, int cap) {
  if (here == m) return 0;
  int &ret = dp[here][y][cap];
  if (ret) return ret;

  ret = max(ret, go(here + 1, y, c));

  for (int i = 0; i < n; i++) {
    bool isbeforeY = (1 << i) & y;
    bool canY = (cap - a[i]) >= 0;
    if (!isbeforeY && canY)
      ret = max(ret, go(here, y | (1 << i), cap - a[i]) + 1);
  }
  return ret;
}

int main() {
  cin >> n >> m >> c;
  for (int i = 0; i < n; i++) cin >> a[i];
  cout << go(0, 0, c);

  return 0;
}
