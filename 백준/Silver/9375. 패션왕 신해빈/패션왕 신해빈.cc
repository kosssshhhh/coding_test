#include <bits/stdc++.h>
using namespace std;

int t, n, answer = 1;
char temp1[24], temp2[24];

int main() {
  cin >> t;

  while (t) {
    map<string, int> mp;
    cin >> n;

    answer = 1;

    for (int i = 0; i < n; i++) {
      scanf("%s %s", temp1, temp2);
      mp[temp2]++;
    }
    for (auto it : mp) {
      // cout << it.first << " : " << it.second << '\n';
      answer *= it.second + 1;
    }

    cout << answer - 1 << '\n';

    t--;
  }
  return 0;
}