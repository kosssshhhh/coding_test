#include <bits/stdc++.h>
using namespace std;

string S, T, ret;
stack<char> stk;

int main() {
  cin >> S >> T;

  for (char a : S) {
    stk.push(a);
    if (stk.size() >= T.size() && stk.top() == T[T.size() - 1]) {
      string s = "";
      for (int i = 0; i < T.size(); i++) {
        s += stk.top();
        stk.pop();
      }
      reverse(s.begin(), s.end());
      if (s != T) {
        for (char b : s) stk.push(b);
      }
    }
  }
  if (stk.empty())
    cout << "FRULA";
  else {
    while (!stk.empty()) {
      ret += stk.top();
      stk.pop();
    }
    reverse(ret.begin(), ret.end());
    cout << ret;
  }
  return 0;
}