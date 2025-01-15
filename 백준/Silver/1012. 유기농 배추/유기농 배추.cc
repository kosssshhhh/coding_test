#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int t, m, n, k, y, x, ret, a[54][54], visited[54][54];

void dfs(int y, int x) {
  visited[y][x] = 1;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny > n || nx > m) continue;
    if (a[ny][nx] == 0 || visited[ny][nx]) continue;
    dfs(ny, nx);
  }
}

int main() {
  cin >> t;

  for (int i = 0; i < t; i++) {
    memset(visited, 0, sizeof(visited));
    memset(a, 0, sizeof(a));
    ret = 0;

    cin >> m >> n >> k;
    for (int j = 0; j < k; j++) {
      cin >> x >> y;
      a[y][x] = 1;
    }
    for (int j = 0; j < n; j++) {
      for (int l = 0; l < m; l++) {
        if (a[j][l] && visited[j][l] == 0) {
          dfs(j, l);
          ret++;
        }
      }
    }
    cout << ret << '\n';
  }

  return 0;
}
