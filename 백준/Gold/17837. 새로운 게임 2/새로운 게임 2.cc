#include <bits/stdc++.h>
using namespace std;

struct Mal {
  int y;
  int x;
  int dir;
};

const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};
int n, k, ret, board[14][14];
vector<int> mal_board[14][14];
vector<Mal> mal;

bool check() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      if (mal_board[i][j].size() >= 4) return true;
  }
  return false;
}

void move(int y, int x, int dir, int i) {
  int ny = y + dy[dir];
  int nx = x + dx[dir];

  if (ny < 0 || ny >= n || nx < 0 || nx >= n || board[ny][nx] == 2) {
    mal[i].dir ^= 1;
    ny = y + dy[mal[i].dir];
    nx = x + dx[mal[i].dir];
    if (ny < 0 || ny >= n || nx < 0 || nx >= n || board[ny][nx] == 2) return;
  }

  vector<int> &here_v = mal_board[y][x];
  vector<int> &next_v = mal_board[ny][nx];

  auto pos = find(here_v.begin(), here_v.end(), i);

  if (board[ny][nx] == 1) reverse(pos, here_v.end());

  for (auto it = pos; it != here_v.end(); it++) {
    next_v.push_back(*it);
    mal[*it].y = ny;
    mal[*it].x = nx;
  }
  here_v.erase(pos, here_v.end());
  return;
}

int solve() {
  int ret = 0;
  while (1) {
    ret++;
    if (ret > 1000) return -1;
    // 번호대로 움직이기
    for (int i = 0; i < mal.size(); i++) {
      int y = mal[i].y;
      int x = mal[i].x;
      int dir = mal[i].dir;
      move(y, x, dir, i);
      if (check()) return ret;
    }

  }
  return ret;
}

int main() {
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < k; i++) {
    int y, x, z;
    cin >> y >> x >> z;
    y--;
    x--;
    z--;
    mal_board[y][x].push_back(i);
    mal.push_back({y, x, z});
  }

  cout << solve();

  return 0;
}