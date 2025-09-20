#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, mx = 0, ret = 0, a[1000004];

bool bs(ll h) {
  ll ret = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] - h > 0) ret += a[i] - h;
  }

  return ret >= m;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }

  ll l = 0, r = mx;

  while (l <= r) {
    ll mid = (l + r) / 2;
    // cout << mid << ' ';

    if (bs(mid)) {
      l = mid + 1;
      ret = mid;
    } else {
      r = mid - 1;
    }
  }

  cout << ret;
  return 0;
}