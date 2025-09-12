#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
  while (true) {
    getline(cin, s);
    if (s == ".") break;

    stack<char> stk;

    for (char c : s) {
      if (c == '(' || c == ')' || c == '[' || c == ']') {
        if (stk.empty())
          stk.push(c);
        else {
          if (c == ')' && stk.top() == '(') {
            stk.pop();
          } else if (c == ']' && stk.top() == '[') {
            stk.pop();
          } else {
            stk.push(c);
          }
        }
      }
    }
    if (stk.empty()) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }

  return 0;
}