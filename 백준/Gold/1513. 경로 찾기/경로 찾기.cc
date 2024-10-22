#include <bits/stdc++.h>
using namespace std;

const int mod = 1000007;
int n, m, c, y, x;
int a[54][54], dp[54][54][54][54];

int go(int y, int x, int cnt, int prevv) {
  if (y > n || x > m) return 0;
  if (y == n && x == m) {
    if (cnt == 0 && a[y][x] == 0) return 1;
    if (cnt == 1 && a[y][x] > prevv) return 1;
    return 0;
  }

  int &ret = dp[y][x][cnt][prevv];
  if (ret != -1) return ret;
  ret = 0;

  if (a[y][x] == 0) {
    ret = (go(y + 1, x, cnt, prevv) + go(y, x + 1, cnt, prevv)) % mod;
  } else if (a[y][x] > prevv) {
    ret =
        (go(y + 1, x, cnt - 1, a[y][x]) + go(y, x + 1, cnt - 1, a[y][x])) % mod;
  }

  return ret;
}

int main() {
  cin >> n >> m >> c;
  for (int i = 1; i <= c; i++) {
    cin >> y >> x;
    a[y][x] = i;
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i <= c; i++) {
    cout << go(1, 1, i, 0) << ' ';
  }

  return 0;
}