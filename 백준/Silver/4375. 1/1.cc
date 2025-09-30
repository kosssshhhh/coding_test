#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  while (cin >> n) {
    int ret = 1, cnt = 1;
    while (true) {
      if (ret % n == 0) {
        cout << cnt << '\n';
        break;
      } else {
        ret = ret * 10 + 1;
        ret %= n;
        cnt++;
      }
    }
  }
  return 0;
}