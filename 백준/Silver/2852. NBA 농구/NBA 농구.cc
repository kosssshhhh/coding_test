#include <bits/stdc++.h>
using namespace std;

int n, team;
int at, bt, as, bs, pre = 0;

string t;

int min_to_sec(string t) {
  int pos;
  int ret;
  pos = t.find(':');
  ret = atoi(t.substr(0, pos).c_str()) * 60 +
        atoi(t.substr(pos + 1, t.length()).c_str());

  return ret;
}

string sec_to_min(int t) {
  string min = to_string(t / 60);
  string sec = to_string(t % 60);
  if (min.length() == 1) min = '0' + min;

  if (sec.length() == 1) sec = '0' + sec;

  return min + ':' + sec;
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> team >> t;

    int a = min_to_sec(t);

    if (as > bs) at += a - pre;

    if (as < bs) bt += a - pre;

    if (team == 1)
      as++;
    else if (team == 2)
      bs++;
    pre = a;
  }

  if (as > bs) at += 2880 - pre;

  if (as < bs) bt += 2880 - pre;

  cout << sec_to_min(at) << '\n' << sec_to_min(bt) << '\n';

  return 0;
}