#include <bits/stdc++.h>
using namespace std;

int t, n;
string temp1, temp2;

int main() {
  cin >> t;
  while (t--) {
    map<string, int> mp;
    int ret = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> temp1 >> temp2;
      mp[temp2]++;
    }

    for (auto a : mp) {
      ret *= a.second + 1;
    }
    cout << ret - 1 << '\n';
  }

  return 0;
}

// map 활용한 조합