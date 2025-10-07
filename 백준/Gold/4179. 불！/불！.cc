#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
const int INF = 1e9;

int r, c, ret;
int fire[1004][1004], jihun[1004][1004];
pair<int, int> jh;
string temp;
char a[1004][1004];
queue<pair<int, int>> q;

int main() {
  cin >> r >> c;
  fill(&fire[0][0], &fire[0][0] + 1004 * 1004, INF);
  for (int i = 0; i < r; i++) {
    cin >> temp;
    for (int j = 0; j < c; j++) {
      a[i][j] = temp[j];
      if (a[i][j] == 'J') {
        jh = {i, j};
      } else if (a[i][j] == 'F') {
        q.push({i, j});
        fire[i][j] = 1;
      }
    }
  }

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i], nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= r || nx >= c || fire[ny][nx] != INF ||
          a[ny][nx] == '#')
        continue;

      fire[ny][nx] = fire[y][x] + 1;
      q.push({ny, nx});
    }
  }

  q.push(jh);
  jihun[jh.first][jh.second] = 1;

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    if (y == r - 1 || x == c - 1 || y == 0 || x == 0) {
      // 바깥 영역인지 확인
      ret = jihun[y][x];
      break;
    }

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i], nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= r || nx >= c || jihun[ny][nx] ||
          a[ny][nx] == '#')
        continue;
      if (fire[ny][nx] <= jihun[y][x] + 1) continue;

      q.push({ny, nx});
      jihun[ny][nx] = jihun[y][x] + 1;
    }
  }

  if (ret == 0)
    cout << "IMPOSSIBLE";
  else
    cout << ret << '\n';

  return 0;
}

// BFS로 퍼뜨리기 (지훈, 불)
// 1. 불 먼저 퍼뜨리기
// 2. 지훈이가 이동하면서 불보다 작아야함
