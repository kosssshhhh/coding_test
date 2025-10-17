#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m;
int visited[54][54], dp[54][54];
char a[54][54];

int go(int y, int x) {
  if (y < 0 || x < 0 || y >= n || x >= m || a[y][x] == 'H') return 0;
  if (visited[y][x]) {
    cout << -1 << '\n';
    exit(0);
  }

  int& ret = dp[y][x];
  if (ret) return ret;

  visited[y][x] = 1;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i] * (a[y][x] - '0');
    int nx = x + dx[i] * (a[y][x] - '0');

    ret = max(ret, go(ny, nx) + 1);
  }

  visited[y][x] = 0;
  return ret;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    for (int j = 0; j < m; j++) {
      a[i][j] = temp[j];
    }
  }

  cout << go(0, 0) << '\n';

  return 0;
}