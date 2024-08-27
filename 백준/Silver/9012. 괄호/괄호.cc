#include <bits/stdc++.h>
using namespace std;

int t;
string temp;
vector<string> v;
stack<char> st;

int main() {
  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> temp;
    v.push_back(temp);
  }

  for (string s : v) {
    while (!st.empty()) st.pop();

    for (int j = 0; j < s.length(); j++) {
      if (st.empty()) {
        st.push(s[j]);
      } else {
        if (st.top() == '(' && s[j] == ')') {
          st.pop();
        } else {
          st.push(s[j]);
        }
      }
    }
    if (st.empty())
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}