#include <bits/stdc++.h>
using namespace std;

const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};
vector<int> dragon[4][11];
int n, x, y, d, g, ret, a[101][101];

void go(int x, int y, int d, int g) {
  a[x][y] = 1;
  for (int i = 0; i <= g; i++) {
    for (int dir : dragon[d][i]) {
      x += dx[dir];
      y += dy[dir];
      a[x][y] = 1;
    }
  }
}

void makeDragon() {
  // 네방향에 대해서
  for (int i = 0; i < 4; i++) {
    dragon[i][0].push_back(i);
    dragon[i][1].push_back((i + 1) % 4);
    for (int j = 2; j <= 10; j++) {
      int n = dragon[i][j - 1].size();
      for (int k = n - 1; k >= 0; k--) {
        dragon[i][j].push_back((dragon[i][j - 1][k] + 1) % 4);
      }
      for (int k = 0; k < n; k++) {
        dragon[i][j].push_back(dragon[i][j - 1][k]);
      }
    }
  }
  return;
}

int main() {
  cin >> n;
  makeDragon();
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> d >> g;
    go(x, y, d, g);
  }

  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 100; j++) {
      if (a[i][j] && a[i + 1][j] && a[i + 1][j + 1] && a[i][j + 1]) ret++;
    }
  }
  cout << ret;
  return 0;
}

// 기하 관련 문제 -> 규칙 찾기 문제
// 방향을 기반으로 규칙 찾아서 해결