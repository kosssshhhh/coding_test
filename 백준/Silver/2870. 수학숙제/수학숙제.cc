#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<string> v;

string go(string s) {
  while (true) {
    if (s.front() == '0')
      s.erase(s.begin());
    else
      break;
  }
  if (s.size() == 0) return "0";
  return s;
}

bool cmp(string a, string b) {
  if (a.size() == b.size()) return a < b;
  return a.size() < b.size();
}

int main() {
  cin >> n;

  while (n--) {
    cin >> s;
    string str = "";

    for (char c : s) {
      if (c < 65) {
        str += c;
      } else if (str.size()) {
        v.push_back(go(str));
        str = "";
      }
    }
    if (str.size()) v.push_back(go(str));
  }

  sort(v.begin(), v.end(), cmp);

  for (string s : v) {
    cout << s << '\n';
  }

  return 0;
}