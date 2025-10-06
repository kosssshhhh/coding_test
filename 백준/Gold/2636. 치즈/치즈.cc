#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, cnt, t;
int a[104][104], visited[104][104];
vector<pair<int, int>> v;

void go(int y, int x) {
  visited[y][x] = 1;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
    if (a[ny][nx] == 1) {
      v.push_back({ny, nx});
      visited[ny][nx] = 1;
    } else {
      go(ny, nx);
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

  while (true) {
    t++;

    for (int i = 0; i < n; i++) {
      go(i, 0);
      go(i, m - 1);
    }
    for (int i = 0; i < m; i++) {
      go(0, i);
      go(n - 1, i);
    }

    if (cnt - v.size() <= 0) break;
    cnt -= v.size();

    for (auto it : v) {
      a[it.first][it.second] = 0;
    }

    memset(visited, 0, sizeof(visited));
    v.clear();
  }

  cout << t << '\n' << cnt;
  return 0;
}