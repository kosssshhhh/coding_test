#include <bits/stdc++.h>
using namespace std;

long long n, x, a[100004], ret;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> x;
  int l = 0, r = n - 1;

  sort(a, a + n);

  while (l < r) {
    if (a[l] + a[r] == x) {
      ret++;
      l++;
      r--;
    } else if (a[l] + a[r] < x) {
      l++;
    } else {
      r--;
    }
  }
  cout << ret;
  return 0;
}