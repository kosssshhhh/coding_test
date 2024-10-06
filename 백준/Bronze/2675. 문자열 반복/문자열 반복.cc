#include <bits/stdc++.h>
using namespace std;

int t, r;
string s;

int main() {
  cin >> t;
  for (int k = 0; k < t; k++) {
    cin >> r >> s;

    for (int i = 0; i < s.length(); i++) {
      for (int j = 0; j < r; j++) cout << s[i];
    }
    cout << '\n';
  }

  return 0;
}