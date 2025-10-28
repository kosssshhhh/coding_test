#include <bits/stdc++.h>
using namespace std;

int n, k, flag, turn = 1;
int visited[2][500004];
queue<int> q;

int main() {
  cin >> n >> k;

  if (n == k) {
    cout << 0;
    return 0;
  }

  visited[0][n] = 1;
  q.push(n);

  while (q.size()) {
    k += turn;
    if (k > 500000) break;

    if (visited[turn % 2][k]) {
      flag = 1;
      break;
    }

    int qSize = q.size();
    for (int i = 0; i < qSize; i++) {
      int x = q.front();
      q.pop();

      for (int nx : {x - 1, x + 1, x * 2}) {
        if (nx < 0 || nx > 500000 || visited[turn % 2][nx]) continue;

        visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1;

        if (nx == k) {
          flag = 1;
          break;
        }
        q.push(nx);
      }
      if (flag) break;
    }
    if (flag) break;
    turn++;
  }

  if (flag)
    cout << turn;
  else
    cout << -1;

  return 0;
}