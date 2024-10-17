#include <bits/stdc++.h>
using namespace std;

long long n, dp[34][34];

long long go(int w, int h) {
  if (w == n) return 1;
  if (w < h) return 0;

  long long &ret = dp[w][h];
  if (ret != -1) return ret;
  ret = 0;

  ret += go(w + 1, h);
  ret += go(w, h + 1);

  return ret;
}

int main() {
  while (1) {
    cin >> n;
    if (n == 0) break;

    memset(dp, -1, sizeof(dp));
    cout << go(0, 0) << '\n';
  }

  return 0;
}