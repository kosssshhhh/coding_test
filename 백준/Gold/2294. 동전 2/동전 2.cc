#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, k, temp, dp[10004];

int main() {
  cin >> n >> k;
  fill(dp, dp + 10004, INF);
  dp[0] = 0;

  for (int i = 0; i < n; i++) {
    cin >> temp;

    for (int j = temp; j <= k; j++) {
      dp[j] = min(dp[j - temp] + 1, dp[j]);
    }
  }

  cout << (dp[k] == INF ? -1 : dp[k]);
  return 0;
}