#include <bits/stdc++.h>
using namespace std;

int a, b, c, mx = 0;

int main() {
  cin >> a >> b >> c;

  if (a != b && b != c && a != c) {
    mx = max(max(a, b), c);
    cout << mx * 100;
  } else if (a == b && b == c && a == c) {
    cout << 10000 + a * 1000;
  } else {
    if (a == b || a == c) {
      cout << 1000 + a * 100;
    } else {
      cout << 1000 + b * 100;
    }
  }

  return 0;
}