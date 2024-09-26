#include <bits/stdc++.h>
using namespace std;

int m;
string s, st;
vector<string> v;

bool cmp(string a, string b) {
  if (a.size() == b.size()) return a < b;
  return a.size() < b.size();
}

void go() {
  while (true) {
    if (st.size() && st.front() == '0')
      st.erase(st.begin());
    else
      break;
  }
  if (st.size() == 0) st = "0";
  v.push_back(st);
  return;
}

int main() {
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> s;
    st = "";
    for (int j = 0; j < s.size(); j++) {
      if (s[j] >= '0' && s[j] <= '9') {
        st += s[j];
      } else {
        if (st != "") {
          go();
          st = "";
        }
      }
    }
    if (st != "") {
      go();
      st = "";
    }
  }

  sort(v.begin(), v.end(), cmp);

  for (string ret : v) {
    cout << ret << '\n';
  }

  return 0;
}