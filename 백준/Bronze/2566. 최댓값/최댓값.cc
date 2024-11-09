#include <bits/stdc++.h>
using namespace std;

int mx, n, m, a[10][10];

int main() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> a[i][j];
      mx = max(a[i][j], mx);
      if (mx == a[i][j]) {
        n = i + 1, m = j + 1;
      }
    }
  }

  cout << mx << '\n';
  cout << n << ' ' << m;

  return 0;
}