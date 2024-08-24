#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int t, m, n, k, x, y, ret;
int a[54][54];
int visited[54][54];

void DFS(int y, int x) {
  visited[y][x] = 1;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny > m || nx < 0 || nx > n || a[ny][nx] == 0) continue;
    if (visited[ny][nx]) continue;

    DFS(ny, nx);
  }
}

int main() {
  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> m >> n >> k;
    for (int j = 0; j < k; j++) {
      cin >> y >> x;
      a[y][x] = 1;
    }

    for (int j = 0; j < m; j++) {
      for (int q = 0; q < n; q++) {
        if (a[j][q] == 0 || visited[j][q]) continue;
        ret++;
        DFS(j, q);
      }
    }

    cout << ret << '\n';
    memset(a, 0, sizeof(a));
    memset(visited, 0, sizeof(visited));
    ret = 0;
  }

  return 0;
}