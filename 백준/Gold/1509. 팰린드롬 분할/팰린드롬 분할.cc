#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
string s;
int dp1[2504][2504], dp2[2504];

int go(int here) {
  if (here == s.size()) return 0;
  if (dp2[here] != INF) return dp2[here];
  int &ret = dp2[here];

  for (int i = 1; here + i <= s.size(); i++) {
    if (dp1[here][i]) ret = min(ret, go(here + i) + 1);
  }
  // cout << here << " : " << ret << "\n";

  return ret;
}

int main() {
  cin >> s;

  for (int i = 0; i < s.size(); i++) dp1[i][1] = 1;
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == s[i + 1]) {
      dp1[i][2] = 1;
    }
  }

  for (int _size = 3; _size <= s.size(); _size++) {
    for (int j = 0; j + _size <= s.size(); j++) {
      if (s[j] == s[j + _size - 1] && dp1[j + 1][_size - 2]) dp1[j][_size] = 1;
    }
  }

  fill(dp2, dp2 + 2504, INF);
  cout << go(0) << '\n';

  return 0;
}