#include <bits/stdc++.h>
using namespace std;
#define y1 aaa

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
bool ok = true;
int n, m, x1, y1, x2, y2, visited[304][304];
char a[304][304];
queue<int> q;

int main() {
  scanf("%d %d", &n, &m);
  scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
  y1--, x1--, y2--, x2--;
  for (int i = 0; i < n; i++) {
    scanf("%s", a[i]);
  }

  q.push(1000 * y1 + x1);
  visited[y1][x1] = 1;
  int cnt = 0;

  while (a[y2][x2] != '0') {
    cnt++;
    queue<int> temp;
    while (q.size()) {
      // y, x 좌표를 변수 하나에 담는 법
      int y = q.front() / 1000;
      int x = q.front() % 1000;
      q.pop();

      for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
        visited[ny][nx] = cnt;
        if (a[ny][nx] != '0') {
          a[ny][nx] = '0';
          temp.push(1000 * ny + nx);
        } else
          q.push(1000 * ny + nx);
      }
    }
    q = temp;
  }

  cout << cnt;
  return 0;
}

// 같은 가중치 그래프 순회: BFS
// Queue를 2개 사용하기
// 최대 범위가 주어졌을 때, x, y 좌표를 한 변수로 표현 가능