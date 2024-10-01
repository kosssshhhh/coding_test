#include <bits/stdc++.h>
using namespace std;

int H, M, ret;

int main() {
  cin >> H >> M;

  int m = H * 60 + M;

  if (m - 45 < 0)
    m = 24 * 60 - (45 - M);
  else
    m -= 45;

  cout << m / 60 << ' ' << (m % 60);

  return 0;
}