#include <bits/stdc++.h>
using namespace std;
#define y1 aaa

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
bool ok = true;
int n, m, x1, y1, x2, y2, y, x, cnt = 1, visited[304][304];
char a[304][304];
string temp;
vector<pair<int, int>> v;

int main() {
  cin >> n >> m;
  cin >> x1 >> y1 >> x2 >> y2;

  for (int i = 0; i < n; i++) {
    cin >> temp;
    for (int j = 0; j < m; j++) {
      a[i][j] = temp[j];
    }
  }

  queue<pair<int, int>> q;
  // visited[y1][x1] = 1;
  // q.push({y1, x1});

  while (ok) {
    cnt++;
    memset(visited, 0, sizeof(visited));
    visited[x1 - 1][y1 - 1] = 1;
    q.push({x1 - 1, y1 - 1});

    while (q.size()) {
      tie(x, y) = q.front();
      q.pop();
      // cout << "x: " << x << " y: " << y << '\n';

      for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || nx >= n || ny >= m || visited[nx][ny]) continue;

        if (nx == x2 - 1 && ny == y2 - 1) {
          ok = false;
          break;
        }
        if (a[nx][ny] == '0') {
          visited[nx][ny] = 1;
          q.push({nx, ny});
        } else if (a[nx][ny] == '1') {
          visited[nx][ny] = 1;
          a[nx][ny] = '0';
        }
      }
      if (!ok) break;
    }
    // a 배열 출력
    // cout << '\n';
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < m; j++) {
    //     cout << a[i][j] << ' ';
    //   }
    //   cout << '\n';
    // }
    if (!ok) break;
  }

  cout << cnt - 1;

  return 0;
}