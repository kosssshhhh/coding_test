#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, dp[1000004];

void go(int here) {
  if (here == 0) return;
  cout << here << ' ';

  if (here % 3 == 0 && dp[here] == dp[here / 3] + 1)
    go(here / 3);
  else if (here % 2 == 0 && dp[here] == dp[here / 2] + 1)
    go(here / 2);
  else if (here - 1 >= 0 && dp[here] == dp[here - 1] + 1)
    go(here - 1);

  return;
}

int main() {
  cin >> n;

  fill(dp, dp + 1000004, INF);

  dp[1] = 0;
  for (int i = 1; i <= n; i++) {
    if (!(i % 3)) dp[i] = min(dp[i / 3] + 1, dp[i]);
    if (!(i % 2)) dp[i] = min(dp[i / 2] + 1, dp[i]);
    dp[i] = min(dp[i - 1] + 1, dp[i]);
  }
  cout << dp[n] << '\n';

  go(n);
  return 0;
}

// DP
// 연산의 겹치는 부분이 발생하고, 부분 최적 구조를 가짐
// trace -> 나눈 값들이 차이가 1 나는 부분을 추적함