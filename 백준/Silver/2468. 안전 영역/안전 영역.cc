#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n, cnt, ret = 1, temp, h;
int a[104][104], visited[104][104];

void dfs(int y, int x) {
  visited[y][x] = 1;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny > n || nx < 0 || nx > n || a[ny][nx] <= h) continue;
    if (visited[ny][nx]) continue;

    if (a[ny][nx] > h && !visited[ny][nx]) dfs(ny, nx);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  for (int k = 0; k <= 100; k++) {
    cnt = 0;
    memset(visited, 0, sizeof(visited));
    h = k;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (visited[i][j] || a[i][j] <= h) continue;
        cnt++;
        dfs(i, j);
      }
    }

    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < n; j++) {
    //     cout << visited[i][j] << ' ';
    //   }
    //   cout << '\n';
    // }

    // cout << '\n';
    ret = max(ret, cnt);
  }

  cout << ret << '\n';

  return 0;
}