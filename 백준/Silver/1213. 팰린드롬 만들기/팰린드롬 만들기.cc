#include <bits/stdc++.h>
using namespace std;

int arr[30], flag;
string s, start, mid, last;

int main() {
  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    arr[s[i] - 'A']++;
  }

  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < arr[i] - 1; j += 2) {
      start += i + 'A';
      last = char(i + 'A') + last;
    }

    if (arr[i] & 1) {
      flag++;
      if (flag > 1) {
        cout << "I'm Sorry Hansoo";
        return 0;
      }
      mid += i + 'A';
    }
  }

  cout << start + mid << last;

  return 0;
}