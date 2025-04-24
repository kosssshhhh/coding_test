#include <bits/stdc++.h>
using namespace std;

string s, ret;

int main() {
  getline(cin, s);

  for (int i = 0; i < s.length(); i++) {
    if (('a' <= s[i] && s[i] <= 'm') || ('A' <= s[i] && s[i] <= 'M'))
      ret += s[i] + 13;
    else if (('n' <= s[i] && s[i] <= 'z') || ('N' <= s[i] && s[i] <= 'Z'))
      ret += s[i] - 13;
    else
      ret += s[i];
  }

  cout << ret << '\n';
  return 0;
}