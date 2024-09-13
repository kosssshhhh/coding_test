#include <bits/stdc++.h>
using namespace std;

int const dy[] = {0, -1, 0, 1};
int const dx[] = {-1, 0, 1, 0};
int n, m, cnt, rm_mx, mx, temp, a[54][54], visited[54][54];

int dfs(int y, int x) {
  visited[y][x] = 1;
  int ret = 1;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= m || nx >= n || visited[ny][nx]) continue;
    if (a[y][x] & (1 << i)) continue;
    ret += dfs(ny, nx);
  }
  return ret;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (visited[i][j]) continue;
      temp = dfs(i, j);
      mx = max(temp, mx);
      cnt++;
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 4; k++) {
        memset(visited, 0, sizeof(visited));
        if (a[i][j] & (1 << k)) {
          a[i][j] &= ~(1 << k);
          temp = dfs(i, j);
          rm_mx = max(temp, rm_mx);
          a[i][j] |= (1 << k);
        }
      }
    }
  }

  cout << cnt << '\n' << mx << '\n' << rm_mx;

  return 0;
}