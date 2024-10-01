#include <bits/stdc++.h>
using namespace std;

int A, B, C;

int main() {
  cin >> A >> B >> C;

  int m = 60 * A + B + C;

  while (m > 60 * 24) {
    m %= 60 * 24;
  }

  if (m / 60 == 24) {
    m -= 24 * 60;
  }

  cout << m / 60 << ' ' << m % 60;

  return 0;
}