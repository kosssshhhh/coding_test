#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, y, x, ret = 987654321, cost[11][11], visited[11][11];
vector<pair<int, int>> position;

void check(vector<pair<int, int>> &a) {
  memset(visited, 0, sizeof(visited));
  int sum = 0;

  for (pair<int, int> point : a) {
    tie(y, x) = point;

    if (visited[y][x]) return;
    visited[y][x] = 1;
    sum += cost[y][x];

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) return;
      visited[ny][nx] = 1;
      sum += cost[ny][nx];
    }
  }
  ret = min(ret, sum);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> cost[i][j];
      position.push_back({i, j});
    }
  }

  for (int i = 0; i < n * n; i++) {
    for (int j = i + 1; j < n * n; j++) {
      for (int k = j + 1; k < n * n; k++) {
        vector<pair<int, int>> v;
        v.push_back(position[i]);
        v.push_back(position[j]);
        v.push_back(position[k]);
        check(v);
      }
    }
  }

  cout << ret;

  return 0;
}