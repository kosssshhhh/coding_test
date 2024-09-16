#include <bits/stdc++.h>
using namespace std;

int n, m, ret, a[5][5], flip[5][5];
string s;

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      a[i][j] = s[j] - '0';
    }
  }

  for (int s = 0; s < (1 << (n * m)); s++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int cur = 0;
      for (int j = 0; j < m; j++) {
        int k = i * m + j;
        if ((s & (1 << k)) == 0) {
          cur = cur * 10 + a[i][j];
        } else {
          sum += cur;
          cur = 0;
        }
      }
      sum += cur;
    }

    for (int j = 0; j < m; j++) {
      int cur = 0;
      for (int i = 0; i < n; i++) {
        int k = i * m + j;
        if ((s & (1 << k)) != 0) {
          cur = cur * 10 + a[i][j];
        } else {
          sum += cur;
          cur = 0;
        }
      }
      sum += cur;
    }

    ret = max(ret, sum);
  }

  cout << ret;
  return 0;
}

// 최대는 무조건 행, 열 쭉 더한게 아닌가 (잘못된 접근)
// 비트마스킹, 브루트포스
// map을 0 or 1 로 표현하여 비트마스킹
// 인덱스 기반