#include <bits/stdc++.h>
using namespace std;

string s;
char prevv;
int flag;

int main() {
  while (1) {
    cin >> s;
    if (s == "end") break;

    bool ism = false;
    int mcnt = 0;
    int jcnt = 0;
    flag = 0;

    for (int i = 0; i < s.size(); i++) {
      if (i > 0 && prevv != 'e' && prevv != 'o' && prevv == s[i]) {
        flag = 1;
        break;
      }
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
          s[i] == 'u') {
        ism = true;
        mcnt++;
        jcnt = 0;
      } else {
        mcnt = 0;
        jcnt++;
      }
      if (mcnt >= 3 || jcnt >= 3) {
        flag = 1;
        break;
      }
      prevv = s[i];
    }

    if (flag == 0 && ism)
      cout << "<" << s << "> is acceptable.\n";
    else
      cout << "<" << s << "> is not acceptable.\n";
  }

  return 0;
}