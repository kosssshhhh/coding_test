#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n, m, visited[104][104];
char a[104][104];
string temp;

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> temp;

    for (int j = 0; j < m; j++) a[i][j] = temp[j];
  }

  visited[0][0] = 1;
  queue<pair<int, int>> q;
  q.push({0, 0});
  int y, x;

  while (q.size()) {
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
      if (visited[ny][nx] || a[ny][nx] == '0') continue;

      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny, nx});
    }
  }

  cout << visited[n - 1][m - 1];

  return 0;
}

// BFS 최단 거리