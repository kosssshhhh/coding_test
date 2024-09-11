#include <bits/stdc++.h>
using namespace std;

int n, l, ret, cnt, a[104][104], b[104][104];
bool flag;

void solve(int a[104][104]) {
  for (int i = 0; i < n; i++) {
    cnt = 1;
    int j;
    for (j = 0; j < n - 1; j++) {
      if (a[i][j] == a[i][j + 1])
        cnt++;
      else if (a[i][j] + 1 == a[i][j + 1] && cnt >= l)
        cnt = 1;  // 오르막
      else if (a[i][j] - 1 == a[i][j + 1] && cnt >= 0)
        cnt = -l + 1;  // 내리막
      else
        break;
    }
    if (j == n - 1 && cnt >= 0) ret++;
  }
}

int main() {
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      b[j][i] = a[i][j];
    }
  }

  solve(a);
  solve(b);

  cout << ret << '\n';
  return 0;
}

// 2차원 배열을 대칭시켜서 행 검사하는 똑같은 로직으로 풀 수 있음
// cnt 변수 한개를 사용해서 오르막, 내리막 둘다 체킹 가능
