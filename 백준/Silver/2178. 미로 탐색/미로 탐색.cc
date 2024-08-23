#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, x, y;
int a[104][104];
int visited[104][104];
string temp;

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> temp;
    for (int j = 0; j < m; j++) {
      a[i][j] = temp[j] - '0';
    }
  }

  queue<pair<int, int>> q;
  q.push({0, 0});
  visited[0][0] = 1;

  while (q.size()) {
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || ny > n || nx < 0 || nx > m || a[ny][nx] == 0) continue;
      if (visited[ny][nx]) continue;
      q.push({ny, nx});
      visited[ny][nx] = visited[y][x] + 1;
    }
  }

  cout << visited[n - 1][m - 1] << '\n';

  return 0;
}