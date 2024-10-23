#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n = 10, ret = INF, a[14][14];
map<int, int> mp;

bool check(int y, int x, int _size) {
  if (y + _size > n || x + _size > n) return false;
  for (int i = y; i < y + _size; i++) {
    for (int j = x; j < x + _size; j++) {
      if (a[i][j] == 0) return false;
    }
  }
  return true;
}

void draw(int y, int x, int _size, int val) {
  for (int i = y; i < y + _size; i++) {
    for (int j = x; j < x + _size; j++) {
      a[i][j] = val;
    }
  }
}

void dfs(int y, int x, int cnt) {
  if (cnt >= ret) return;
  if (x == n) {
    dfs(y + 1, 0, cnt);
    return;
  }
  if (y == n) {
    ret = min(ret, cnt);
    return;
  }

  if (a[y][x] == 0) {
    dfs(y, x + 1, cnt);
    return;
  }
  for (int i = 5; i >= 1; i--) {
    if (mp[i] == 5) continue;
    if (check(y, x, i)) {
      mp[i]++;
      draw(y, x, i, 0);
      dfs(y, x + i, cnt + 1);
      draw(y, x, i, 1);
      mp[i]--;
    }
  }
  return;
}

int main() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cin >> a[i][j];
  }

  dfs(0, 0, 0);  // y, x, cnt

  cout << (ret == INF ? -1 : ret);

  return 0;
}

// 큰 색종이를 먼저 붙이면 되지 않을까
// 최소를 찾는 문제인데 경우의 수에서 이미 최소보다 큰것들은 백트래킹 할 수 있지
// 않을까 원복 할 수 있지 않을까