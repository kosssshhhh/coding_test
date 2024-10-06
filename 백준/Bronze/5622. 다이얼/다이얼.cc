#include <bits/stdc++.h>
using namespace std;

int cnt[200], ret;
string s;

void setDial() {
  cnt['A'] = 3, cnt['B'] = 3, cnt['C'] = 3;
  cnt['D'] = 4, cnt['E'] = 4, cnt['F'] = 4;
  cnt['G'] = 5, cnt['H'] = 5, cnt['I'] = 5;
  cnt['J'] = 6, cnt['K'] = 6, cnt['L'] = 6;
  cnt['M'] = 7, cnt['N'] = 7, cnt['O'] = 7;
  cnt['P'] = 8, cnt['Q'] = 8, cnt['R'] = 8, cnt['S'] = 8;
  cnt['T'] = 9, cnt['U'] = 9, cnt['V'] = 9;
  cnt['W'] = 10, cnt['X'] = 10, cnt['Y'] = 10, cnt['Z'] = 10;
}

int main() {
  cin >> s;
  setDial();
  for (int i = 0; i < s.length(); i++) ret += cnt[s[i]];

  cout << ret;

  return 0;
}