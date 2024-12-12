#include <bits/stdc++.h>
using namespace std;

int n, m, temp;
int cnt[41], dp[41];

int go(int idx) {
  if (idx >= n - 1) return 1;
  if (cnt[idx]) return go(idx + 1);  // 현재 idx가 고정석

  int &ret = dp[idx];
  if (ret != -1) return ret;
  ret = 0;

  if (!cnt[idx + 1])  // 다음 idx 고정석이 아님
    ret += (go(idx + 2) + go(idx + 1));
  else
    ret += go(idx + 1);

  return ret;
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    cin >> temp;
    cnt[temp - 1] = 1;
  }

  memset(dp, -1, sizeof(dp));

  cout << go(0) << '\n';

  return 0;
}