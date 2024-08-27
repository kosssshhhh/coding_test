#include <bits/stdc++.h>
using namespace std;

string s;

bool check(string s) {
  stack<char> stk;
  for (int c : s) {
    if (c == '[' || c == ']' || c == '(' || c == ')') {
      if (c == '(' || c == '[')
        stk.push(c);
      else {
        if (stk.empty())
          return false;
        else {
          if (stk.top() == '(' && c == ')')
            stk.pop();
          else if (stk.top() == '[' && c == ']')
            stk.pop();
          else
            return false;
        }
      }
    }
  }
  return stk.empty();
}

int main() {
  while (true) {
    getline(cin, s);

    if (s == ".") break;

    if (check(s))
      cout << "yes\n";
    else
      cout << "no\n";
  }

  return 0;
}