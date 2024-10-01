#include <bits/stdc++.h>
using namespace std;

int n, m, cnt[104], i, j, k;

int main() {
  cin >> n >> m;
  for (int t = 0; t < m; t++) {
    cin >> i >> j >> k;
    for (int a = i; a <= j; a++) {
      cnt[a] = k;
    }
  }
  for (int i = 1; i <= n; i++) cout << cnt[i] << ' ';

  return 0;
}