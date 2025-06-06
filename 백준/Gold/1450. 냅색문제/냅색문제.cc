#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, c, ret, a[32];
vector<int> v, v2;

void go(int here, int _n, vector<int> &v, int sum) {
  if (sum > c) return;
  if (here > _n) {
    v.push_back(sum);
    return;
  }
  go(here + 1, _n, v, sum + a[here]);
  go(here + 1, _n, v, sum);
  return;
}

int main() {
  cin >> n >> c;
  for (int i = 0; i < n; i++) cin >> a[i];

  go(0, n / 2 - 1, v, 0);
  go(n / 2, n - 1, v2, 0);
  sort(v.begin(), v.end());
  sort(v2.begin(), v2.end());

  for (int b : v) {
    if (c - b >= 0)
      ret += ((int)(upper_bound(v2.begin(), v2.end(), c - b) - v2.begin()));
  }

  cout << ret;

  return 0;
}

// Meet in the middle
// n이 너무 크지만 DP로 풀기엔 상태값을 담기 어렵고, 완탐을 해야하는 문제
// N/2 로 나눠서 해결
