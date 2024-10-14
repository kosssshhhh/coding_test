#include <bits/stdc++.h>
using namespace std;

long long n, dp[94];

int main() {
  cin >> n;

  dp[0] = 0, dp[1] = 1;
  for (int i = 2; i <= 90; i++) {
    dp[i] = dp[i - 2] + dp[i - 1];
  }
  cout << dp[n];

  return 0;
}