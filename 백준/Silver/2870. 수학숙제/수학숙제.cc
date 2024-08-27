#include <bits/stdc++.h>
using namespace std;

int n;
string s, num = "";
vector<string> v;

bool cmp(string a, string b) {
  if (a.size() == b.size()) return a < b;
  return a.size() < b.size();
}

void go() {
  while (true) {
    if (num.size() && num.front() == '0')
      num.erase(num.begin());
    else
      break;
  }

  if (num.size() == 0) num = "0";
  v.push_back(num);
  return;
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> s;
    num = "";

    for (int j = 0; j < s.size(); j++) {
      if (s[j] >= '0' && s[j] <= '9')
        num += s[j];
      else {
        if (num != "") {
          go();
          num = "";
        }
      }

      if (num != "" && j == s.size() - 1) {
        // 마지막 숫자일 경우
        go();
        num = "";
      }
    }
  }

  sort(v.begin(), v.end(), cmp);

  for (string a : v) cout << a << '\n';

  return 0;
}