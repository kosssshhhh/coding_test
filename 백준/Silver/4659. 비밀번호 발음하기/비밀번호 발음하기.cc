#include <bits/stdc++.h>
using namespace std;

string s;
char a[] = {'a', 'e', 'i', 'o', 'u'};
bool m = true;

bool ism(char c) {
  bool check = false;
  for (int i = 0; i < 5; i++) {
    if (a[i] == c) {
      check = true;
      return check;
    } else
      continue;
  }
  return check;
}

int main() {
  while (true) {
    m = true;
    cin >> s;
    if (s == "end") break;

    for (int i = 0; i < s.size(); i++) {
      if (ism(s[i])) {
        m = true;
        break;
      } else {
        m = false;
        continue;
      }
    }
    if (!m) {
      cout << "<" << s << "> is not acceptable.\n";
      continue;
    }

    for (int i = 0; i < s.size() - 2; i++) {
      if (s.size() < 3) break;
      bool a = ism(s[i]);
      bool b = ism(s[i + 1]);
      bool c = ism(s[i + 2]);
      if (a == b && b == c && a == c) {
        m = false;
        break;
      } else {
        continue;
      }
    }
    if (!m) {
      cout << "<" << s << "> is not acceptable.\n";
      continue;
    }

    for (int i = 0; i < s.size() - 1; i++) {
      if (s.size() < 2) break;
      if (s[i] == s[i + 1]) {
        if (s[i] == 'e' || s[i] == 'o') {
          continue;
        } else {
          m = false;
          break;
        }
      } else {
        continue;
      }
    }
    if (!m) {
      cout << "<" << s << "> is not acceptable.\n";
      continue;
    }

    if (m) cout << "<" << s << "> is acceptable.\n";
  }

  return 0;
}