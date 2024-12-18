#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, w, a[1025][1025], tree[1025][1025];

void update(int y, int x, int val) {
  while (y <= n) {
    int j = x;
    while (j <= n) {
      tree[y][j] += val;
      j += j & -j;
    }
    y += y & -y;
  }
  return;
}

int sum(int y, int x) {
  int ret = 0;
  while (y > 0) {
    int j = x;
    while (j > 0) {
      ret += tree[y][j];
      j -= j & -j;
    }
    y -= y & -y;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      update(i, j, a[i][j]);
    }
  }
  for (int t = 0; t < m; t++) {
    cin >> w;
    if (w) {
      // 합 구하기
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;

      cout << sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) +
                  sum(x1 - 1, y1 - 1)
           << '\n';

    } else {
      // 바꾸는 연산 (update)
      int x, y, c;
      cin >> x >> y >> c;
      update(x, y, c - a[x][y]);
      a[x][y] = c;
    }
  }

  return 0;
}

// 2차원 팬윅트리
// 1차원과 동일하게 진행
// 이중 while문 사용할 때, 안쪽 변수 새로 선언해서 진행