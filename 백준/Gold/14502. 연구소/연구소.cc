#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int m, n, cnt, ret = 100, wall_cnt;
int a[10][10], visited[10][10];
vector<pair<int, int>> v;

void dfs(int y, int x) {
  visited[y][x] = 1;
  cnt++;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
    if (a[ny][nx] == 0 && visited[ny][nx] == 0) {
      dfs(ny, nx);
    }
  }
}

int main() {
  cin >> m >> n;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];

      if (a[i][j] == 0) v.push_back({i, j});
      if (a[i][j] == 1) wall_cnt++;
    }
  }

  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      for (int k = j + 1; k < v.size(); k++) {
        a[v[i].first][v[i].second] = 1;
        a[v[j].first][v[j].second] = 1;
        a[v[k].first][v[k].second] = 1;

        for (int l = 0; l < m; l++) {
          for (int o = 0; o < n; o++) {
            if (a[l][o] == 2 && visited[l][o] == 0) {
              dfs(l, o);
            }
          }
        }
        ret = min(cnt, ret);
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        a[v[i].first][v[i].second] = 0;
        a[v[j].first][v[j].second] = 0;
        a[v[k].first][v[k].second] = 0;
      }
    }
  }
  cout << m * n - ret - wall_cnt - 3 << '\n';

  return 0;
}