#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, wall_cnt, cnt, ret = 1e9, a[10][10], visited[10][10];
vector<pair<int, int>> v;

void go(int y, int x) {
  visited[y][x] = 1;
  cnt++;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;
    if (a[ny][nx] == 0) go(ny, nx);
  }
}

int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
      if (a[i][j] == 0) {
        v.push_back({i, j});
      } else if (a[i][j] == 1) {
        wall_cnt++;
      }
    }
  }

  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      for (int k = j + 1; k < v.size(); k++) {
        a[v[i].first][v[i].second] = 1;
        a[v[j].first][v[j].second] = 1;
        a[v[k].first][v[k].second] = 1;

        for (int l = 0; l < N; l++) {
          for (int m = 0; m < M; m++) {
            if (a[l][m] == 2 && !visited[l][m]) go(l, m);
          }
        }

        ret = min(ret, cnt);
        cnt = 0;
        memset(visited, 0, sizeof(visited));

        a[v[i].first][v[i].second] = 0;
        a[v[j].first][v[j].second] = 0;
        a[v[k].first][v[k].second] = 0;
      }
    }
  }

  cout << M * N - wall_cnt - 3 - ret;
  return 0;
}