#include <bits/stdc++.h>
using namespace std;

int n, ret;
long long m;
int arr[15004];

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) cin >> arr[i];

  // 문제 조건에 따라 불가능한 조건
  if (m > 200000)
    cout << 0 << "\n";

  else {
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        if (m == arr[i] + arr[j]) ret++;
      }
    cout << ret << '\n';
  }

  return 0;
}

// 두 개를 선택하여 ~ -> 조합
// 문제의 조건에서 일어날 수 없는 경우를 예외처리해준다.
// 시간초과가 빡빡한 문제의 경우 이러한 조건을 생각해주어야할 필요도 있음.
