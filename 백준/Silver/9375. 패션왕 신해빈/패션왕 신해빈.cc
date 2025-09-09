#include <bits/stdc++.h>
using namespace std;

int t, n;
string a, b;

int main() {
  cin >> t;

  while (t--) {
    cin >> n;
    map<string, int> mp;

    for (int i = 0; i < n; i++) {
      cin >> a >> b;
      mp[b]++;
    }

    int ret = 1;

    for (auto it : mp) {
      ret *= it.second + 1;
    }

    cout << ret - 1 << '\n';
  }

  return 0;
}