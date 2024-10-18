#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, k, a[104], dp[10004];

int main() {
  cin >> n >> k;

  for (int i = 0; i < n; i++) cin >> a[i];

  fill(dp, dp + 10004, INF);

  dp[0] = 0;

  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < n; j++) {
      if (i - a[j] >= 0) dp[i] = min(dp[i - a[j]] + 1, dp[i]);
    }
  }

  cout << (dp[k] == INF ? -1 : dp[k]);

  return 0;
}