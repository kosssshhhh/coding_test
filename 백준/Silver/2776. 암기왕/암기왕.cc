#include <bits/stdc++.h>
using namespace std;

int t, n, m, temp;
unordered_map<int, int> mp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;
  while (t--) {
    mp.clear();

    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      mp[temp] = 1;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
      cin >> temp;

      if (mp[temp]) {
        cout << 1 << '\n';
      } else {
        cout << 0 << '\n';
      }
    }
  }

  return 0;
}