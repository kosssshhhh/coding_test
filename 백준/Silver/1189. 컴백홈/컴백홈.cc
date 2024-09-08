#include <bits/stdc++.h>
using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int m, n, k, ret, visited[7][7];
char a[7][7];

void go(int y, int x, int cnt) {
  // 기저사례ret
  if (a[y][x] == 'T') return;
  if (y == 0 && x == n - 1) {
    if (k == cnt) ret++;
    return;
  }

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= m || nx >= n || visited[ny][nx]) continue;
    if (a[ny][nx] == 'T') continue;
    visited[ny][nx] = 1;
    go(ny, nx, cnt + 1);
    visited[ny][nx] = 0;
  }
}

int main() {
  cin >> m >> n >> k;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  visited[m - 1][0] = 1;
  go(m - 1, 0, 1);

  cout << ret;

  return 0;
}