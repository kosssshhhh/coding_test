#include <bits/stdc++.h>
using namespace std;

int n;
double a[10004];

double go() {
  double mx = -1e9;
  for (int start = 0; start < n; start++) {
    double curr = 1.0;
    for (int end = start; end < n; end++) {
      curr *= a[end];
      mx = max(mx, curr);
    }
  }
  return mx;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  double ret = go();

  cout << fixed << setprecision(3) << ret << '\n';

  return 0;
}