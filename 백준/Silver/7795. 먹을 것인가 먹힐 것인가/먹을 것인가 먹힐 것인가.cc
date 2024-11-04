#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int main() {
  cin >> t;
  while (t--) {
    int ret = 0;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
      auto pos = lower_bound(b.begin(), b.end(), a[i]);
      ret += (int)(pos - b.begin());
    }
    cout << ret << '\n';
  }

  return 0;
}

// 두 배열 모두 정렬 후, lower_bound를 활용하여 풀이