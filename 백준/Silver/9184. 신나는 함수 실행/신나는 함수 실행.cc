#include <bits/stdc++.h>
using namespace std;

int a, b, c, dp[104][104][104];

int go(int a, int b, int c) {
  if (a <= 0 || b <= 0 || c <= 0) return 1;

  int& ret = dp[a + 50][b + 50][c + 50];
  if (ret != -1) return ret;

  if (a > 20 || b > 20 || c > 20)
    return ret = go(20, 20, 20);

  else if (a < b && b < c)
    return ret = go(a, b, c - 1) + go(a, b - 1, c - 1) - go(a, b - 1, c);

  else {
    return ret = go(a - 1, b, c) + go(a - 1, b - 1, c) + go(a - 1, b, c - 1) -
                 go(a - 1, b - 1, c - 1);
  }
}

int main() {
  memset(dp, -1, sizeof(dp));
  dp[50][50][50] = 1;
  while (1) {
    cin >> a >> b >> c;
    if (a == -1 && b == -1 && c == -1) break;
    printf("w(%d, %d, %d) = %d\n", a, b, c, go(a, b, c));
  }

  return 0;
}