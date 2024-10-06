#include <bits/stdc++.h>
using namespace std;

int n, m, a[104], ret, mn = 987654321;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        // cout << i << ' ' << j << ' ' << k << '\n';
        int sum = a[i] + a[j] + a[k];
        int temp = m - sum;
        if (sum <= m && mn > temp) {
          mn = temp;
          ret = sum;
        }
      }
    }
  }

  cout << ret;

  return 0;
}