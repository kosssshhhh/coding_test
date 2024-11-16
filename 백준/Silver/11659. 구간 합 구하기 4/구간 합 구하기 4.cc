#include <bits/stdc++.h>
using namespace std;

int n, m, l, r, temp, psum[100004];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    cin >> temp;
    psum[i] += psum[i - 1] + temp;
  }

  for (int i = 0; i < m; i++) {
    cin >> l >> r;
    cout << psum[r] - psum[l - 1] << '\n';
  }

  return 0;
}