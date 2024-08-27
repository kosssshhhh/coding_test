#include <bits/stdc++.h>
using namespace std;

int n;
string s;

bool check(string s) {
  stack<char> stk;
  for (char c : s) {
    if (c == '(')
      stk.push(c);
    else {
      if (!stk.empty())
        stk.pop();
      else
        return false;
    }
  }
  return stk.empty();
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (check(s))
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}

// Stack은 {짝짓기, 폭발, 아름다운 괄호} 키워드 기억
// 중첩 반복문에서 i j 잘 구분해서 작성하기