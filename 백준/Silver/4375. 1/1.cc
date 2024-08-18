#include <bits/stdc++.h>
using namespace std;

int n, cnt = 1;
unsigned long long temp = 1;

int main() {
  while (1) {
    cin >> n;
    if (cin.eof() == 1) break;
    temp = 1;
    cnt = 1;
    while (1) {
      temp %= n;
      if (temp % n == 0) {
        cout << cnt << '\n';
        break;
      }
      cnt++;
      temp = 1 + temp * 10;
    }
  }
  return 0;
}