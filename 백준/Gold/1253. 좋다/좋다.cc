#include <bits/stdc++.h>
using namespace std;

int n, ret, a[2004];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a, a + n);

  for (int i = 0; i < n; i++) {
    int l = 0, r = n - 1;

    while (l < r) {
      if (i == l) l++;
      if (i == r) r--;
      if (l >= r) break;

      int sum = a[l] + a[r];
      //   cout << a[i] << ": " << sum << '\n';
      if (sum == a[i]) {
        ret++;
        break;
      } else if (sum < a[i])
        l++;
      else
        r--;
    }
  }

  cout << ret;

  return 0;
}