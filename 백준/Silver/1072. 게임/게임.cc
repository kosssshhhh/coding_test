#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x, y, z, ret;

bool check(int mid) {
  ll temp_x = x + mid;
  ll temp_y = y + mid;

  ll percent = temp_y * 100 / temp_x;

  if (percent != z) {
    return true;
  }
  return false;
}

int main() {
  cin >> x >> y;

  z = y * 100 / x;

  ll lo = 1, hi = 1000000004;

  while (lo <= hi) {
    ll mid = (lo + hi) / 2;

    if (check(mid)) {
      // 증가할 때
      ret = mid;
      hi = mid - 1;
    } else {
      // 값이 똑같을 때
      lo = mid + 1;
    }
  }

  cout << (ret ? ret : -1);
  return 0;
}