#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int m, n, k, xf, yf, xl, yl, ret, cnt = 0;
int a[104][104], visited[104][104];

void dfs(int y, int x) {
  visited[y][x] = 1;
  cnt++;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
    if (a[ny][nx] || visited[ny][nx]) continue;
    dfs(ny, nx);
  }
  return;
}

int main() {
  cin >> m >> n >> k;
  vector<int> v;

  for (int i = 0; i < k; i++) {
    cin >> xf >> yf >> xl >> yl;

    for (int i = yf; i < yl; i++) {
      for (int j = xf; j < xl; j++) {
        a[i][j] = 1;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (visited[i][j] || a[i][j]) continue;
      ret++;
      dfs(i, j);

      v.push_back(cnt);
      cnt = 0;
    }
  }

  cout << ret << '\n';
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';

  return 0;
}