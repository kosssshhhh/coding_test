#include <bits/stdc++.h>
using namespace std;

int N, ret;
string s;
map<string, int> mp;

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> s;
    if (s == "ENTER") {
      mp.clear();
    } else {
      mp[s]++;
      if (mp[s] == 1) {
        ret++;
      }
    }
  }

  cout << ret << '\n';
  return 0;
}