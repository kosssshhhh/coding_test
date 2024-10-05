#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, cnt[104];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cnt[i] = i;
  }
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    int temp = cnt[a];
    cnt[a] = cnt[b];
    cnt[b] = temp;
  }

  for (int i = 1; i <= n; i++) cout << cnt[i] << ' ';

  return 0;
}