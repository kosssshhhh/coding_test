#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, a[1004][1004], visited[1004][1004][2];
struct Item {
  int y;
  int x;
  int is_wall_broken;
};

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%1d", &a[i][j]);
    }
  }

  // BFS N, M, 벽 깨짐 여부
  queue<Item> q;
  visited[0][0][0] = 1;
  q.push({0, 0, 0});

  while (q.size()) {
    int y = q.front().y;
    int x = q.front().x;
    int is_wall_broken = q.front().is_wall_broken;
    // cout << "y: " << y << " x: " << x << " is_wall_broken: " <<
    // is_wall_broken
    //      << '\n';
    q.pop();

    if (y == n - 1 && x == m - 1) {
      cout << visited[y][x][is_wall_broken] << '\n';
      return 0;
    }

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

      // 벽이 없고, 방문하지 않은곳
      if (a[ny][nx] == 0 && !visited[ny][nx][is_wall_broken]) {
        visited[ny][nx][is_wall_broken] = visited[y][x][is_wall_broken] + 1;
        q.push({ny, nx, is_wall_broken});
      } else if (a[ny][nx] == 1 && !is_wall_broken && !visited[ny][nx][1]) {
        // 벽이 있고, 벽을 부순적이 없고, 방문하지 않은곳
        visited[ny][nx][1] = visited[y][x][0] + 1;
        q.push({ny, nx, 1});
      }
    }
  }

  cout << -1 << '\n';

  return 0;
}