#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, cnt, ret, a[104][104], visited[104][104];
vector<pair<int, int>> v;

void dfs(int y, int x) {
  visited[y][x] = 1;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
    if (a[ny][nx] == 1 && visited[ny][nx] == 0) {
      v.push_back({ny, nx});
      visited[ny][nx] = 1;
    } else if (a[ny][nx] == 0 && visited[ny][nx] == 0) {
      dfs(ny, nx);
    }
  }
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 1) cnt++;
    }
  }

  while (cnt > 0) {
    ret++;
    for (int i = 0; i < n; i++) {
      dfs(i, 0);
      dfs(i, m);
    }
    for (int i = 0; i < m; i++) {
      dfs(0, i);
      dfs(n, i);
    }

    if (cnt - v.size() <= 0) break;

    cnt -= v.size();

    for (auto it : v) {
      a[it.first][it.second] = 0;
    }

    v.clear();
    memset(visited, 0, sizeof(visited));
  }

  cout << ret << '\n' << cnt;

  return 0;
}