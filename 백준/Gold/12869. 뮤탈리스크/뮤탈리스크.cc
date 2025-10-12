#include <bits/stdc++.h>
using namespace std;

struct A {
  int a, b, c;
};

int attacks[6][3] = {{9, 3, 1}, {9, 1, 3}, {3, 9, 1},
                     {3, 1, 9}, {1, 9, 3}, {1, 3, 9}};

int n, scv[3];
int visited[62][62][62];
queue<A> q;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> scv[i];
  }

  visited[scv[0]][scv[1]][scv[2]] = 1;
  q.push({scv[0], scv[1], scv[2]});

  while (q.size()) {
    int a = q.front().a;
    int b = q.front().b;
    int c = q.front().c;
    q.pop();
    if (a == 0 && b == 0 && c == 0) continue;

    for (int i = 0; i < 6; i++) {
      int na = max(0, a - attacks[i][0]);
      int nb = max(0, b - attacks[i][1]);
      int nc = max(0, c - attacks[i][2]);

      if (visited[na][nb][nc]) continue;

      visited[na][nb][nc] = visited[a][b][c] + 1;
      q.push({na, nb, nc});
    }
  }

  cout << visited[0][0][0] - 1 << '\n';

  return 0;
}