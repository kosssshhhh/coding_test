#include <bits/stdc++.h>
using namespace std;

int n, idx[104], mx;

int main() {
  for (int i = 0; i < 9; i++) {
    cin >> n;
    idx[n] = i + 1;
    mx = max(mx, n);
  }

  cout << mx << '\n' << idx[mx];
  return 0;
}