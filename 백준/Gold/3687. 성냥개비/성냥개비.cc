#include <bits/stdc++.h>
using namespace std;

int t, n, a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string dp[104], MAX_STR = "111111111111111111111111111111111111111111111111119";

string get_min_str(string a, string b) {
  if (a.size() == b.size()) return (a < b ? a : b);
  if (a.size() < b.size()) return a;
  return b;
}

string findMax(int here) {
  string ret = "";
  if (here & 1) {
    ret += '7';
    here -= 3;
  }
  while (here) {
    ret += '1';
    here -= 2;
  }
  return ret;
}

int main() {
  cin >> t;

  fill(dp, dp + 104, MAX_STR);
  dp[0] = "";

  for (int i = 2; i < 104; i++) {
    for (int j = 0; j <= 9; j++) {
      if (i - a[j] < 0) continue;
      if (j == 0 && dp[i - a[j]] == "") continue;
      dp[i] = get_min_str(dp[i], dp[i - a[j]] + to_string(j));
    }
  }

  while (t--) {
    cin >> n;
    cout << dp[n] << ' ' << findMax(n) << '\n';
  }

  return 0;
}

// DP, 그리디
// MAX 값의 경우, 문자열의 길이가 길면 되기 때문에 그리디로 풀이
// MIN 값의 경우, 문자열을 활용한 DP로 풀이