#include <bits/stdc++.h>
using namespace std;

long long n, m, cnt, mx, a[100004], ret = 987654321;

bool check(int val) {
  if (val < mx) return false;
  long long sum = 0;
  cnt = 1;
  for (int i = 0; i < n; i++) {
    if (sum + a[i] <= val) {
      sum += a[i];
    } else {
      cnt++;
      sum = 0;
      sum += a[i];
    }
  }
  return cnt <= m;
}

int main() {
  cin >> n >> m;
  long long total = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
    total += a[i];
  }

  // sort(a, a + n);
  long long l = 1, r = total, mid;

  while (l <= r) {
    mid = (l + r) / 2;
    if (check(mid)) {
      // cout << mid << '\n';
      ret = mid;
      r = mid - 1;
    } else {
      // cout << mid << '\n';
      l = mid + 1;
    }
  }
  cout << ret;
  return 0;
}