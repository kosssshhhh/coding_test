#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, m, a[100004], ret = INF, mx = -1, total;

bool check(int bill) {
  if (bill < mx) return false;
  int cnt = 1, sum = 0;

  for (int i = 0; i < n; i++) {
    if (sum + a[i] > bill) {
      //
      cnt++;
      sum = a[i];
    } else {
      sum += a[i];
    }
    if (cnt > m) return false;
  }
  // cout << "bill: " << bill << " cnt: " << cnt << '\n';
  return true;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
    total += a[i];
  }

  int lo = mx, hi = total, ret = hi;

  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    if (check(mid)) {
      // cout << "mid: " << mid << '\n';
      ret = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  cout << ret;

  return 0;
}