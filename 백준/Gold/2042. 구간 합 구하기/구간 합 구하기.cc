#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, k, a, b, c, arr[1000004], tree[1000004];

void update(int idx, ll val) {
  while (idx <= n) {
    tree[idx] += val;
    idx += idx & -idx;
  }
}

ll sum(int idx) {
  ll ret = 0;
  while (idx > 0) {
    ret += tree[idx];
    idx -= idx & -idx;
  }
  return ret;
}

ll query(int l, int r) { return sum(r) - sum(l - 1); }

int main() {
  cin >> n >> m >> k;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; i++) {
    update(i, arr[i]);
  }

  for (int i = 0; i < m + k; i++) {
    cin >> a >> b >> c;

    if (a == 1) {
      // b번째 수를 c로 바꾸기
      update(b, c - arr[b]);
      arr[b] = c;

    } else if (a == 2) {
      // b~c 번째 수의 합
      cout << query(b, c) << '\n';
    }
  }

  return 0;
}