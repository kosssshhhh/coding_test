#include <bits/stdc++.h>
using namespace std;

int n, a[13], cnt[4];
int mn = 1100000000, mx = -1100000000;

void go(int idx, int sum) {
  if (idx == n) {
    mn = min(sum, mn);
    mx = max(sum, mx);
    return;
  }
  int temp = sum;
  for (int i = 0; i < 4; i++) {
    if (cnt[i] == 0) continue;
    if (i == 0) {
      sum += a[idx];
    } else if (i == 1) {
      sum -= a[idx];
    } else if (i == 2) {
      sum *= a[idx];
    } else if (i == 3) {
      sum /= a[idx];
    }
    cnt[i]--;
    go(idx + 1, sum);
    sum = temp;
    cnt[i]++;
  }

  return;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  for (int i = 0; i < 4; i++) cin >> cnt[i];

  go(1, a[0]);

  cout << mx << '\n' << mn;
  return 0;
}