#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, l, r, sum, cnt, ret, a[54][54], visited[54][54];
vector<pair<int, int>> v;

void dfs(int y, int x) {
  visited[y][x] = 1;
  v.push_back({y, x});

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
    int d = abs(a[y][x] - a[ny][nx]);
    if (d >= l && d <= r) {
      // cout << "d: " << d << '\n';
      dfs(ny, nx);
    }
  }
}

int main() {
  cin >> n >> l >> r;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  while (true) {
    cnt = 0;
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (visited[i][j]) continue;

        v.clear();
        sum = 0;

        dfs(i, j);
        if (v.size() <= 1)
          continue;
        else {
          cnt++;
          // cout << "vsize: " << v.size() << '\n';
          // for(auto t : v) cout << a[t.first][t.second] << ' ';
          // cout << '\n';
          for (pair<int, int> p : v) {
            sum += a[p.first][p.second];
          }
          int avg = sum / v.size();
          for (pair<int, int> p : v) {
            a[p.first][p.second] = avg;
          }
        }
      }
    }
    if (!cnt) break;
    ret++;
  }

  // for (int i=0; i< n; i++){
  //   for (int j=0; j<n; j++){
  //     cout << a[i][j]<< ' ';
  //   }cout << '\n';
  // }

  cout << ret;

  return 0;
}