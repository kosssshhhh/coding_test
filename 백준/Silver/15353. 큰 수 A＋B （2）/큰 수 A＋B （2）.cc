#include <bits/stdc++.h>
using namespace std;

string s1, s2, big, sm;
int s, temp, sum;
vector<char> v;

int main() {
  cin >> s1 >> s2;

  if (s1.size() >= s2.size()) {
    s = s1.size();
    big = s1.substr(0, s1.size());
    sm = s2.substr(0, s2.size());
  } else {
    s = s2.size();
    big = s2.substr(0, s2.size());
    sm = s1.substr(0, s1.size());
  }

  reverse(big.begin(), big.end());
  reverse(sm.begin(), sm.end());

  for (int i = 0; i <= s; i++) {
    if (s == i) {
      if (temp == 1) v.push_back('1');
      break;
    }

    if (i > sm.size() - 1) {
      sum = (big[i] - '0') + temp;

    } else {
      sum = (sm[i] - '0') + (big[i] - '0') + temp;
    }
    if (sum >= 10)
      temp = 1;
    else
      temp = 0;

    char c = (sum % 10) + '0';

    v.push_back(c);
  }

  reverse(v.begin(), v.end());
  for (char c : v) {
    cout << c;
  }
  cout << '\n';
  return 0;
}