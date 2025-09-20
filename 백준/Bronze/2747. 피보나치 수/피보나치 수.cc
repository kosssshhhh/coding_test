#include <bits/stdc++.h>
using namespace std;

int n, dp[50];

int fibo(int n) {
  if (n <= 1) return n;

  int &ret = dp[n];
  if (ret != -1) return ret;

  return ret = fibo(n - 1) + fibo(n - 2);
}

int main() {
  cin >> n;

  memset(dp, -1, sizeof(dp));

  cout << fibo(n);

  return 0;
}