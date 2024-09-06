#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int r, c, y, x, mx, t, visited[24][24], cnt[30];
string s;
char a[24][24];

void dfs(int y, int x) {
  mx = max(mx, t);

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx]) continue;
    if (cnt[a[ny][nx] - 'A']) continue;
    visited[ny][nx] = 1;
    cnt[a[ny][nx] - 'A'] = 1;
    t++;
    dfs(ny, nx);
    visited[ny][nx] = 0;
    t--;
    cnt[a[ny][nx] - 'A'] = 0;
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

  visited[0][0] = 1;
  cnt[a[0][0] - 'A']++;
  t++;

  dfs(0, 0);

  cout << mx;
  return 0;
}