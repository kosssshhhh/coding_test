#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int r, c, y, x, mx, visited[30];
string s;
char a[24][24];

void dfs(int y, int x, int cnt) {
  mx = max(mx, cnt);

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
    if (visited[a[ny][nx] - 'A']) continue;
    visited[a[ny][nx] - 'A'] = 1;
    cnt++;
    dfs(ny, nx, cnt);
    cnt--;
    visited[a[ny][nx] - 'A'] = 0;
  }
}

int main() {
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    cin >> s;
    for (int j = 0; j < c; j++) {
      a[i][j] = s[j];
    }
  }

  visited[a[0][0] - 'A']++;

  dfs(0, 0, 1);

  cout << mx;
  return 0;
}

// 완탐, 원복
// 시간 복잡도 애매
// 풀이 방법이 완탐밖에 없어보임
// visited 배열에 알파벳을 넣어서 visited 배열 구현
