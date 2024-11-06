#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, atk, ret;
int temp1, temp2, temp3;
struct Room {
  int t, a, h;
} v[130000];

bool check(ll mid) {
  ll mxHP = mid;
  ll init_atk = atk;
  // 방 n개 만큼 반복
  for (int i = 0; i < n; i++) {
    if (v[i].t == 1) {
      // 몬스터
      // 몬스터가 용사를 떄리는 수
      ll cnt = v[i].h / init_atk;
      if (v[i].h % init_atk) cnt++;
      // 몬스터가 용사 공격
      mid -= (cnt - 1) * v[i].a;

    } else if (v[i].t == 2) {
      // 포션
      init_atk += v[i].a;
      mid = min(mid + v[i].h, mxHP);
    }
    if (mid <= 0) return false;
  }
  return true;
}

int main() {
  cin >> n >> atk;

  for (int i = 0; i < n; i++) {
    cin >> temp1 >> temp2 >> temp3;
    v[i] = {temp1, temp2, temp3};
  }

  ll lo = 0, hi = 1e18 + 4;
  ret = 1e18 + 56;

  while (lo <= hi) {
    ll mid = (lo + hi) / 2;

    if (check(mid)) {
      ret = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  cout << ret;

  return 0;
}