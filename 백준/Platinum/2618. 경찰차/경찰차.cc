#include <bits/stdc++.h>
using namespace std;

int n, w, px[1003], py[1003], dp[1003][1003], y, x;

int d(int a, int b) { return abs(px[a] - px[b]) + abs(py[a] - py[b]); }

int go(int a, int b) {
  if (a == w + 1 || b == w + 1) return 0;

  if (dp[a][b]) return dp[a][b];
  int _next = max(a, b) + 1;

  return dp[a][b] = min(go(a, _next) + d(b, _next), go(_next, b) + d(a, _next));
}

void trace() {
  int a = 0, b = 1;
  for (int i = 2; i < w + 2; i++) {
    if (dp[i][b] + d(a, i) < dp[a][i] + d(b, i))
      puts("1"), a = i;
    else
      puts("2"), b = i;
  }
  return;
}

int main() {
  cin >> n >> w;

  py[0] = 1, px[0] = 1;
  py[1] = n, px[1] = n;

  for (int i = 2; i < w + 2; i++) {
    cin >> y >> x;
    py[i] = y, px[i] = x;
  }

  cout << go(0, 1) << '\n';  // go(경찰차 1의 위치, 경찰차 2의 위치)
  trace();

  return 0;
}