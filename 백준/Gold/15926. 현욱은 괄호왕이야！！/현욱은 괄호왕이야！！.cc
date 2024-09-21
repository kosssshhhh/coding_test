#include <bits/stdc++.h>
using namespace std;

int n, cnt, mx, arr[200004];
string s;
stack<int> stk;

int main() {
  cin >> n >> s;

  for (int i = 0; i < n; i++) {
    if (stk.empty()) {
      stk.push(i);
      continue;
    }
    if (s[stk.top()] == '(' && s[i] == ')') {
      arr[stk.top()] = 1;
      arr[i] = 1;
      stk.pop();
    } else {
      stk.push(i);
    }
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1) {
      cnt++;
      mx = max(cnt, mx);
    } else
      cnt = 0;
  }

  cout << mx;
  return 0;
}

// 1. 배열을 이용하는 방법
// stack에 string의 인덱스를 넣어줌
// match 되면, arr에 해당 index 1로 바꿈
// arr의 연속된 1을 구해준다.
