#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, k, temp, ret = -INF, psum[100004];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> temp;
    psum[i] = psum[i - 1] + temp;
  }

  for (int i = k; i <= n; i++) {
    int sum = psum[i] - psum[i - k];

    ret = max(ret, sum);
  }

  cout << ret;

  return 0;
}