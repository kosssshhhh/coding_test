#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  while (scanf("%d", &n) != EOF) {
    long long temp = 1;
    int cnt = 1;

    while (true) {
      if (temp % n == 0) {
        cout << cnt << '\n';
        break;
      }
      temp = temp * 10 + 1;
      cnt++;
      temp %= n;
    }
  }

  return 0;
}