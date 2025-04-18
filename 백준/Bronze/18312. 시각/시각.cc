#include <bits/stdc++.h>
using namespace std;

int n, k, ret;

string to_string2(int a) {
  string s = "";
  if (a / 10 == 0) {
    s = '0' + to_string(a);
  } else {
    s = to_string(a);
  }
  return s;
}

bool check_string(int sec) {
  int h = 0, m = 0;

  h = sec / (60 * 60);
  sec %= 60 * 60;
  m = sec / (60);
  sec %= 60;
  string sh, sm, ss;

  sh = to_string2(h);
  sm = to_string2(m);
  ss = to_string2(sec);

  // cout << sh << ' ' << sm << ' ' << ss << '\n';
  // cout << to_string(h).find(char(k)) << '\n';
  string temp = to_string(k);
  if (sh.find(temp) != string::npos || sm.find(temp) != string::npos ||
      ss.find(temp) != string::npos) {
    // cout << "hit\n";
    return true;
  } else
    return false;
}

int main() {
  cin >> n >> k;

  int sec = 59;
  sec += 59 * 60;
  sec += n * 60 * 60;

  for (int i = sec; i >= 0; i--)
    if (check_string(i)) ret++;

  cout << ret;
  return 0;
}
