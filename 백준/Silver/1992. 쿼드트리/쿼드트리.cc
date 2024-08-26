#include <bits/stdc++.h>
using namespace std;

int n, sx, sy, ex, ey;
int a[68][68];

void Recursion(int sy, int sx, int ey, int ex) {
  int init = a[sy][sx];
  bool flag = true;
  if (ey <= 0 || ex <= 0 || sy >= n || sx >= n) return;
  if (sy < 0 || sx < 0 || ey > n || ex > n) return;

  // cout << "sy : " << sy << " sx : " << sx << " ey : " << ey << " ex : " << ex
  //      << '\n';

  for (int i = sy; i < ey; i++) {
    for (int j = sx; j < ex; j++) {
      if (init != a[i][j]) flag = false;
    }
  }
  if (flag) {
    cout << init;
    return;
  } else {
    cout << '(';
    int my = (sy + ey) / 2;
    int mx = (sx + ex) / 2;
    Recursion(sy, sx, my, mx);
    Recursion(sy, mx, my, ex);
    Recursion(my, sx, ey, mx);
    Recursion(my, mx, ey, ex);
    cout << ')';
  }
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%1d", &a[i][j]);
    }
  }

  // cout << '(';
  Recursion(0, 0, n, n);
  // cout << ')';
  return 0;
}