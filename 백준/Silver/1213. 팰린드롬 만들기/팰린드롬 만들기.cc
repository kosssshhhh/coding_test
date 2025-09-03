#include <bits/stdc++.h>
using namespace std;

string s, start, mid, last;
int flag, cnt[30];

int main() {
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    cnt[s[i] - 'A']++;
  }

  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < cnt[i] - 1; j += 2) {
      start += i + 'A';
      last = char(i + 'A') + last;
    }

    if (cnt[i] & 1) {
      flag++;
      if (flag > 1) {
        cout << "I'm Sorry Hansoo";
        return 0;
      } else {
        mid += i + 'A';
      }
    }
  }

  cout << start + mid + last;

  return 0;
}