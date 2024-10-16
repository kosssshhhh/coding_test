#include <bits/stdc++.h>
using namespace std;

int n, a[17][17], dp[17][17][3];

int go(int y, int x, int d) {
  if (y < 0 || x < 0 || y >= n || x >= n) return 0;
  if (a[y][x]) return 0;
  if (d == 1) {
    if (a[y - 1][x]) return 0;
    if (a[y][x - 1]) return 0;
  }

  if (y == n - 1 && x == n - 1) return 1;

  int &ret = dp[y][x][d];
  if (ret != -1) return ret;

  ret = 0;

  if (d == 0) {
    ret += go(y, x + 1, 0);
    ret += go(y + 1, x + 1, 1);
  } else if (d == 1) {
    ret += go(y, x + 1, 0);
    ret += go(y + 1, x + 1, 1);
    ret += go(y + 1, x, 2);
  } else if (d == 2) {
    ret += go(y + 1, x + 1, 1);
    ret += go(y + 1, x, 2);
  }
  return ret;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  memset(dp, -1, sizeof(dp));

  cout << go(0, 1, 0);

  return 0;
}