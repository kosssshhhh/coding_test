#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, cnt, mx, a[104][104], visited[104][104];

void dfs(int y, int x, int h) {
  visited[y][x] = 1;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
    if (a[ny][nx] <= h) continue;
    dfs(ny, nx, h);
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  for (int h = 1; h <= 100; h++) {
    cnt = 0;
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] <= h || visited[i][j]) continue;
        dfs(i, j, h);
        cnt++;
      }
    }
    mx = max(cnt, mx);
  }
  if (mx == 0) {
    cout << 1;
    return 0;
  }
  cout << mx;
  return 0;
}