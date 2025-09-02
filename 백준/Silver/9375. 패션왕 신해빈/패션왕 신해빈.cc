#include <bits/stdc++.h>
using namespace std;

int t, n;
string s1, s2;

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    map<string, int> mp;
    int ret = 1;

    for (int i = 0; i < n; i++) {
      cin >> s1 >> s2;

      mp[s2]++;
    }
    for (auto it : mp) {
      ret *= it.second + 1;
    }

    cout << ret - 1 << '\n';
  }

  return 0;
}