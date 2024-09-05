#include <bits/stdc++.h>
using namespace std;

const int max_n = 500000;
int visited[2][max_n + 4], a, b, ok, turn = 1;

int main() {
  cin >> a >> b;

  if (a == b) {
    cout << 0 << '\n';
    return 0;
  }

  queue<int> q;
  visited[0][a] = 1;
  q.push(a);

  while (q.size()) {
    b += turn;
    if (b > max_n) break;
    if (visited[turn % 2][b]) {
      ok = true;
      break;
    }
    int qSize = q.size();
    for (int i = 0; i < qSize; i++) {
      int x = q.front();
      q.pop();

      for (int nx : {x + 1, x - 1, x * 2}) {
        if (nx < 0 || nx > max_n || visited[turn % 2][nx]) continue;
        visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1;

        if (nx == b) {
          ok = 1;
          break;
        }
        q.push(nx);
      }
      if (ok) break;
    }
    if (ok) break;
    turn++;
  }

  if (ok)
    cout << turn << '\n';
  else
    cout << -1 << '\n';

  return 0;
}

// flood fill: BFS에서 같은 레벨에 있는 값에 같은 조건을 적용하고 싶을 때
// 수빈이가 홀짝인지 체크: 동생이 수빈이가 도착했던 포인트에 이후에 도착해도 -1, 1 반복하며 동생과 만날 수 있음.