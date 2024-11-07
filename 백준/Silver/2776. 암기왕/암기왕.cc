#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> v1(n);
    for (int i = 0; i < n; i++) cin >> v1[i];
    cin >> m;
    vector<int> v2(m);
    for (int i = 0; i < m; i++) cin >> v2[i];

    sort(v1.begin(), v1.end());

    for (int val : v2) {
      int ret = 0;
      int lo = 0, hi = n;

      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        // cout << "val: " << val << '\n';
        // cout << "mid: " << mid << '\n';
        if (v1[mid] == val) {
          ret = 1;
          break;
        } else if (v1[mid] > val) {
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }
      cout << ret << '\n';
    }
  }

  return 0;
}