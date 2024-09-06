#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int m, n, a[104][104], t, cnt;
int visited[104][104];
vector<pair<int, int>> v;

void dfs(int y, int x) {
  visited[y][x] = 1;
  // cout << y << " : " << x << '\n';
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
    if (a[ny][nx] == 1 && visited[ny][nx] == 0) {
      // cout << "get\n";
      v.push_back({ny, nx});
      visited[ny][nx] = 1;
    }
    if (a[ny][nx] == 0 && visited[ny][nx] == 0) dfs(ny, nx);
  }
  return;
}

int main() {
  cin >> m >> n;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 1) cnt++;
    }
  }
  // cout << cnt << '\n';

  while (cnt > 0) {
    t++;
    // 치즈 겉면 확인
    for (int j = 0; j < n; j++) {
      dfs(0, j);
      dfs(m, j);
    }
    for (int j = 0; j < m; j++) {
      dfs(j, 0);
      dfs(j, n);
    }
    // 치즈 개수 0인지 확인
    // cout << "겉 치즈 개수 : " << v.size() << '\n';
    if (cnt - v.size() <= 0) break;

    // 치즈 개수 업데이트
    cnt = cnt - v.size();
    // cout << "cnt : " << cnt << '\n';
    // 치즈 제거
    for (auto k : v) {
      a[k.first][k.second] = 0;
    }

    // cout << '\n';
    // for (int i = 0; i < m; i++) {
    //   for (int j = 0; j < n; j++) {
    //     cout << a[i][j] << ' ';
    //   }
    //   cout << "\n";
    // }
    memset(visited, 0, sizeof(visited));
    v.clear();
  }

  cout << t << '\n' << cnt;

  return 0;
}