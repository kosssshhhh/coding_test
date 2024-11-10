#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, a[1000004], ret, sum;

bool check(ll mid) {
  ll cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += a[i] / mid;
  }
  if (cnt >= m)
    return true;
  else
    return false;
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  ll lo = 1, hi = 1e9;

  while (lo <= hi) {
    ll mid = (lo + hi) / 2;

    if (check(mid)) {
      ret = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  cout << sum - (ret * m);
  return 0;
}

// 파 여러개 사옴
// 각각의 파닭에 같은 양의 파를 넣음
// 파를 최대한 많이 넣음

// 이분탐색
