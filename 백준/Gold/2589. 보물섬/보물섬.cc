#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, y, x, ret = -1;
int a[54][54], visited[54][54];
vector<pair<int, int>> v;

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    for (int j = 0; j < m; j++) {
      if (temp[j] == 'L') {
        a[i][j] = 1;
        v.push_back({i, j});
      } else {
        a[i][j] = 0;
      }
    }
  }
  for (int t = 0; t < v.size(); t++) {
    int mx = -1;
    memset(visited, 0, sizeof(visited));

    queue<pair<int, int>> q;
    visited[v[t].first][v[t].second] = 1;
    q.push(v[t]);

    while (q.size()) {
      tie(y, x) = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
        if (a[ny][nx]) {
          q.push({ny, nx});
          visited[ny][nx] = visited[y][x] + 1;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        mx = max(visited[i][j], mx);
        // cout << visited[i][j] << ' ';
      }
      //   cout << '\n';
    }

    ret = max(ret, mx);
  }

  cout << ret - 1;
  return 0;
}