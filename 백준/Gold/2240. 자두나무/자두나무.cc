#include <bits/stdc++.h>
using namespace std;

int t, w, b[1004];
int dp[1004][2][32];

int go(int time, int idx, int cnt) {
  if (cnt < 0) return -1e9;
  if (time == t) return cnt == 0 ? 0 : -1e9;

  int &ret = dp[time][idx][cnt];
  if (ret != -1) return ret;

  ret = 0;

  return ret = max(go(time + 1, idx ^ 1, cnt - 1), go(time + 1, idx, cnt)) +
               (b[time] - 1 == idx);
}

int main() {
  cin >> t >> w;
  for (int i = 0; i < t; i++) cin >> b[i];

  memset(dp, -1, sizeof(dp));
  cout << max(go(0, 1, w - 1), go(0, 0, w));

  return 0;
}