#include <bits/stdc++.h>
using namespace std;

int N, M, J, a, l, r, ret;

int main() {
  cin >> N >> M >> J;

  l = 1, r = l + M - 1;

  for (int i = 0; i < J; i++) {
    cin >> a;

    if (r < a) {
      ret += a - r;
      l += a - r;
      r = a;

    } else if (a < l) {
      ret += l - a;
      r -= l - a;
      l = a;
    } else {
      continue;
    }
  }
  cout << ret;

  return 0;
}