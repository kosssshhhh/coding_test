#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int r, c, y, x, ret;
string temp;
char a[1004][1004];
int f_check[1004][1004], p_check[1004][1004];
queue<pair<int, int>> q;
pair<int, int> ji;

bool in(int a, int b) { return 0 <= a && a < r && 0 <= b && b < c; }

void bfs_f(int y, int x) {}

int main() {
  cin >> r >> c;
  fill(&f_check[0][0], &f_check[0][0] + 1004 * 1004, INF);
  for (int i = 0; i < r; i++) {
    cin >> temp;
    for (int j = 0; j < c; j++) {
      a[i][j] = temp[j];
      if (a[i][j] == 'F') {
        f_check[i][j] = 1;
        q.push({i, j});
      } else if (a[i][j] == 'J')
        ji = {i, j};
    }
  }

  while (q.size()) {
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (!in(ny, nx)) continue;
      if (f_check[ny][nx] != INF || a[ny][nx] == '#') continue;
      f_check[ny][nx] = f_check[y][x] + 1;
      q.push({ny, nx});
    }
  }

  p_check[ji.first][ji.second] = 1;
  q.push(ji);
  while (q.size()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    if (x == c - 1 || y == r - 1 || x == 0 || y == 0) {
      ret = p_check[y][x];
      break;
    }
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (!in(y, x)) continue;
      if (p_check[ny][nx] || a[ny][nx] == '#') continue;
      if (f_check[ny][nx] <= p_check[y][x] + 1) continue;
      p_check[ny][nx] = p_check[y][x] + 1;
      q.push({ny, nx});
    }
  }
  if (ret != 0)
    cout << ret << '\n';
  else
    cout << "IMPOSSIBLE";

  return 0;
}