#include <bits/stdc++.h>
using namespace std;

int n, k, ret = -1e9, psum[100004];

int main() {
  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    int temp;
    cin >> temp;
    psum[i] = psum[i - 1] + temp;
  }

  for (int i = k; i <= n; i++) {
    ret = max(ret, psum[i] - psum[i - k]);
  }

  cout << ret;

  return 0;
}