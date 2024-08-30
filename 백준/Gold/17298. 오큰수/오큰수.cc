#include <bits/stdc++.h>
using namespace std;

int n, a[1000004], mx;
int ret[1000004];
stack<int> stk;

int main() {
  cin >> n;
  memset(ret, -1, sizeof(ret));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    while (stk.size() && a[stk.top()] < a[i]) {
      ret[stk.top()] = a[i];
      stk.pop();
    }
    stk.push(i);
  }

  for (int i = 0; i < n; i++) cout << ret[i] << ' ';

  return 0;
}

// 짝짓기 (Stack) 로 풀 생각을 못떠올림
// 보통의 비교를 하게 되면 시간복잡도를 초과할 것이라 생각하여, 방법을 찾던 중 요소의 뒤부터 참조하는 것을 생각함.
// 생각의 흐름을 자료구조와 알고리즘으로 매핑시키는 능력이 필요.
// 뭔가 짝을 짓는다고 하면 Stack을 생각하기.