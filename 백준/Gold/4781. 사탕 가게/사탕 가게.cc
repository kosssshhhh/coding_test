#include <bits/stdc++.h>
using namespace std;

int n, c, m, m1, m2;
int dp[10004];

int main() {
  while (1) {
    scanf("%d %d.%d", &n, &m1, &m2);
    if (n == 0) break;

    int cost = m1 * 100 + m2;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
      scanf("%d %d.%d", &c, &m1, &m2);

      int m = m1 * 100 + m2;

      for (int j = m; j <= cost; j++) {
        dp[j] = max(dp[j], dp[j - m] + c);
      }
    }
    cout << dp[cost] << '\n';
  }

  return 0;
}