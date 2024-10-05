#include <bits/stdc++.h>
using namespace std;

int cnt[30];
string s;

int main() {
  cin >> s;
  memset(cnt, -1, sizeof(cnt));

  for (int i = 0; i < s.size(); i++) {
    if (cnt[s[i] - 'a'] == -1) {
      cnt[s[i] - 'a'] = i;
    }
  }

  for (int i = 0; i < 26; i++) {
    cout << cnt[i] << ' ';
  }

  return 0;
}