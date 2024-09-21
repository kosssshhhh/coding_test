#include <bits/stdc++.h>
using namespace std;

int n, cnt, mx, arr[200004];
string s;
stack<int> stk;

int main() {
  cin >> n >> s;

  stk.push(-1);
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') stk.push(i);
    if (s[i] == ')') {
      stk.pop();
      if (!stk.empty()) {
        mx = max(mx, i - stk.top());
      } else {
        stk.push(i);
      }
    }
  }

  cout << mx;
  return 0;
}

// 2. stk 이용하는 방법
// 우선 stk에 -1 push
// ( 들어오면 stk에 i push
// ) 들어오면 stk.pop() 후 stk.top() 으로 최대 길이 구해줌
// if pop 했는데 stk이 비었다면 i push