#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int m, n, cnt, ret = 0, wall_cnt; // ret 초기값을 0으로 수정
int a[10][10], visited[10][10];
vector<pair<int, int>> v;

void dfs(int y, int x) {
  visited[y][x] = 1;
  cnt++;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    // 배열 범위 체크 조건 수정: '> m' -> '>= m' 그리고 '> n' -> '>= n'
    if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue; // 수정된 부분
    if (a[ny][nx] == 0 && visited[ny][nx] == 0) {
      dfs(ny, nx);
    }
  }
}

int main() {
  cin >> m >> n;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];

      if (a[i][j] == 0) v.push_back({i, j});
      if (a[i][j] == 1) wall_cnt++;
    }
  }

  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      for (int k = j + 1; k < v.size(); k++) {
        a[v[i].first][v[i].second] = 1;
        a[v[j].first][v[j].second] = 1;
        a[v[k].first][v[k].second] = 1;

        cnt = 0; // cnt 초기화 위치 변경 (여기서 초기화해야 정확한 카운트가 됨)
        for (int l = 0; l < m; l++) {
          for (int o = 0; o < n; o++) {
            if (a[l][o] == 2 && visited[l][o] == 0) {
              dfs(l, o);
            }
          }
        }

        // ret 값을 업데이트하는 로직 수정 (최대 안전 영역을 계산)
        ret = max(m * n - cnt - wall_cnt - 3, ret); // 수정된 부분

        memset(visited, 0, sizeof(visited)); // visited 배열 초기화
        a[v[i].first][v[i].second] = 0;
        a[v[j].first][v[j].second] = 0;
        a[v[k].first][v[k].second] = 0;
      }
    }
  }
  
  cout << ret << '\n'; // 최대 안전 영역 출력

  return 0;
}