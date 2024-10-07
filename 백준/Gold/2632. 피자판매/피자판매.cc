#include <bits/stdc++.h>
using namespace std;

int dest, m, n, ret, a[1004], b[1004], psum_a[2004], psum_b[2004];
map<int, int> cnt_a, cnt_b;

void make(int n, int psum[], map<int, int>& mp) {
  for (int interval = 1; interval <= n; interval++) {
    for (int start = interval; start <= n + interval - 1; start++) {
      int sum = psum[start] - psum[start - interval];
      mp[sum]++;
      if (interval == n) break;
    }
  }
}

int main() {
  cin >> dest;
  cin >> m >> n;

  for (int i = 1; i <= m; i++) {
    cin >> a[i];
    psum_a[i] = psum_a[i - 1] + a[i];
  }
  for (int i = m + 1; i <= 2 * m; i++) {
    psum_a[i] = psum_a[i - 1] + a[i - m];
  }

  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    psum_b[i] = psum_b[i - 1] + b[i];
  }
  for (int i = n + 1; i <= 2 * n; i++) {
    psum_b[i] = psum_b[i - 1] + b[i - n];
  }

  make(m, psum_a, cnt_a);
  make(n, psum_b, cnt_b);

  ret = (cnt_a[dest] + cnt_b[dest]);

  for (int i = 0; i < dest; i++) {
    ret += cnt_a[i] * cnt_b[dest - i];
  }
  cout << ret;

  return 0;
}
