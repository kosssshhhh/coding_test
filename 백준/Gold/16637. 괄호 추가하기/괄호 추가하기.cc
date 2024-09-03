#include <bits/stdc++.h>
using namespace std;

int n, ret = -987654321;
vector<char> op;
vector<int> num;
string temp;

int oper(char _op, int a, int b) {
  if (_op == '+')
    return a + b;
  else if (_op == '-')
    return a - b;
  else if (_op == '*')
    return a * b;
  else
    return 0;
}

void go(int here, int _num) {
  if (here == num.size() - 1) {
    ret = max(ret, _num);
    return;
  }

  go(here + 1, oper(op[here], _num, num[here + 1]));

  if (here + 2 <= num.size() - 1) {
    int temp = oper(op[here + 1], num[here + 1], num[here + 2]);
    go(here + 2, oper(op[here], _num, temp));
  }
}

int main() {
  cin >> n;
  cin >> temp;
  for (int i = 0; i < n; i++) {
    if (i % 2)
      op.push_back(temp[i]);
    else
      num.push_back(temp[i] - '0');
  }
  go(0, num[0]);

  cout << ret;

  return 0;
}

// 재귀, 완전탐색
// 작은 단위, 쉬운 예제부터 생각해보자
// 작은 단위에서 문제를 어떻게 쪼갤 수 있는지