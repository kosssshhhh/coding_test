#include <bits/stdc++.h>
using namespace std;

int n, cnt, mx, arr[200004];
string s;
stack<int> stk;

int main() {
  cin >> n >> s;

  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      stk.push(i);
    } else {
      if (stk.empty()) {
        stk.push(i);
      } else {
        if (s[stk.top()] == '(') {
          arr[stk.top()] = 1;
          arr[i] = 1;
          stk.pop();
        } else {
          stk.push(i);
        }
      }
    }
    mx = max(mx, cnt);
  }

  // for (int i = 0; i < n; i++) {
  //   if (stk.empty()) {
  //     stk.push(i);
  //     continue;
  //   }
  //   if (s[stk.top()] == '(' && s[i] == ')') {
  //     arr[stk.top()] = 1;
  //     arr[i] = 1;
  //     stk.pop();
  //   } else {
  //     stk.push(i);
  //   }
  // }
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1) {
      cnt++;
      mx = max(cnt, mx);
    } else {
      mx = max(cnt, mx);
      cnt = 0;
    }
  }

  cout << mx;
  return 0;
}

// '(' 얘는 일단 다 넣음
// ')' 얘가 들어올때마다 매칭 되는게 있으면 cnt++ 하고 없으면 cnt 초기화
