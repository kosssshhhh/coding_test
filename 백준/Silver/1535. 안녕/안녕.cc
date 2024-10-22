#include <bits/stdc++.h>
using namespace std;

int n, a[24], b[24];
int dp[104];
int main() {
  cin >> n;

  for (int i = 0; i < n; i++) cin >> a[i];  // 체력
  for (int i = 0; i < n; i++) cin >> b[i];  // 기쁨

  for (int i = 0; i < n; i++) {
    for (int j = 100; j >= a[i]; j--) {
      dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
    }
  }
  cout << dp[99];

  return 0;
}