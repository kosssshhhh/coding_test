#include <bits/stdc++.h>
using namespace std;

int n, m, j, ret;
int a;

int main() {
  cin >> n >> m;
  cin >> j;

  int l = 1;
  int r = m;

  for (int i = 0; i < j; i++) {
    cin >> a;
    if (a > r) {
      while (a != r) {
        l++;
        r++;
        ret++;
      }
    }
    if (a < l) {
      while (a != l) {
        l--;
        r--;
        ret++;
      }
    }
    if (a <= r && a >= l) {
      continue;
    }
  }

  cout << ret;

  return 0;
}