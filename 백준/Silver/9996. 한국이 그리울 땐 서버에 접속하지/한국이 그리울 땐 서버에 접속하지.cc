#include <bits/stdc++.h>
using namespace std;

int N;
string pat, s;

int main() {
  cin >> N >> pat;

  int pos = pat.find('*');
  string pre = pat.substr(0, pos);
  string suf = pat.substr(pos + 1);

  for (int i = 0; i < N; i++) {
    cin >> s;

    if (s.size() < pre.size() + suf.size()) {
      cout << "NE\n";
    } else {
      if (s.substr(0, pre.size()) == pre &&
          s.substr(s.size() - suf.size()) == suf) {
        cout << "DA\n";
      } else {
        cout << "NE\n";
      }
    }
  }

  return 0;
}