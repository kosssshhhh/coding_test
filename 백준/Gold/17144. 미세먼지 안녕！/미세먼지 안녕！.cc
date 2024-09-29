#include <bits/stdc++.h>
using namespace std;

const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};
const int ddy[] = {0, 1, 0, -1};
const int ddx[] = {1, 0, -1, 0};
int R, C, T, ret, a[54][54], temp[54][54];

void dfs(int y, int x) {
  int cnt = 0;
  int here = a[y][x];
  temp[y][x] += here;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= R || nx >= C || a[ny][nx] == -1) continue;

    temp[ny][nx] += here / 5;
    cnt++;
  }
  if (cnt) temp[y][x] -= here / 5 * cnt;
}

void air(int y, int x, int m) {
  int mode = 0;
  int prevv = 0;
  int here_y = y;
  int here_x = x;

  while (a[here_y][here_x] != -1) {
    int ny = 0, nx = 0;
    if (m == 0) {
      ny = here_y + dy[mode];
      nx = here_x + dx[mode];
    } else if (m == 1) {
      ny = here_y + ddy[mode];
      nx = here_x + ddx[mode];
    }

    if (ny < 0 || nx < 0 || ny >= R || nx >= C) {
      mode++;
      continue;
    }
    int temp = a[here_y][here_x];
    a[here_y][here_x] = prevv;

    prevv = temp;
    here_y = ny, here_x = nx;
  }
}

int main() {
  cin >> R >> C >> T;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> a[i][j];
    }
  }

  while (T) {
    // 먼지 확산
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (a[i][j] == -1) {
          temp[i][j] = a[i][j];
          continue;
        }
        if (a[i][j] == 0) continue;
        dfs(i, j);
      }
    }

    // temp -> a
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        a[i][j] = temp[i][j];
      }
    }

    // 공기청정기
    int m = 0;
    for (int i = 0; i < R; i++) {
      if (a[i][0] == -1) {
        air(i, 1, m);
        m++;
      }
    }
    T--;
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (a[i][j] != -1) {
        ret += a[i][j];
      }
    }
  }
  cout << ret;

  return 0;
}

// 구현
// 먼지 확산 -> 공기청정기 -> T번 반복 -> 먼지 합산
// 동시 먼지 확산 구현하기 위해 temp 배열 생성
// 공기 청정기 범위의 끝 만날때마다 dy dx 바꿔줌