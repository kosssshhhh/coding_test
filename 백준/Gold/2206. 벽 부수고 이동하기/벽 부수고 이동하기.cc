#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, a[1004][1004], dist[1004][1004][2];

struct Item {
  int y;
  int x;
  int is_wall_broke;
};

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) scanf("%1d", &a[i][j]);
  }

  queue<Item> q;

  q.push({0, 0, 0});
  dist[0][0][0] = 1;

  while (!q.empty()) {
    int y = q.front().y;
    int x = q.front().x;
    int is_wall_broke = q.front().is_wall_broke;
    q.pop();

    if (y == n - 1 && x == m - 1) {
      cout << dist[y][x][is_wall_broke] << '\n';
      return 0;
    }

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

      // 벽이 없고, 방문하지 않은 경우
      if (!a[ny][nx] && !dist[ny][nx][is_wall_broke]) {
        dist[ny][nx][is_wall_broke] = dist[y][x][is_wall_broke] + 1;

        q.push({ny, nx, is_wall_broke});
      }
      // 벽이 있고, 벽을 부순적이 없고, 방문하지 않은 경우
      else if (a[ny][nx] && !is_wall_broke && !dist[ny][nx][is_wall_broke]) {
        dist[ny][nx][1] = dist[y][x][is_wall_broke] + 1;

        q.push({ny, nx, 1});
      }
    }
  }

  cout << -1 << '\n';

  return 0;
}