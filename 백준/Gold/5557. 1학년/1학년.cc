#include <bits/stdc++.h>
using namespace std;

int n, a[104];
long long dp[104][21];

long long go(int here, int hap) {
  if (hap > 20 || hap < 0 || here > n - 1) return 0;
  if (here == n - 1 && hap == a[n - 1]) {
    // cout << "here : " << here << " hap : " << hap << '\n';
    return 1;
  }

  long long &ret = dp[here][hap];
  if (ret != -1) return ret;

  ret = 0;
  ret += go(here + 1, hap + a[here]);
  ret += go(here + 1, hap - a[here]);

  return ret;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  memset(dp, -1, sizeof(dp));

  cout << go(1, a[0]);

  return 0;
}