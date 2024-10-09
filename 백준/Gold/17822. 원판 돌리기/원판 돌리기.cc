#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, T, x, d, k, ret, visited[54][104];
vector<int> a[54];

void _rotate(int x, int d, int k) {
  if (d) {
    // 반시계
    rotate(a[x].begin(), a[x].begin() + k, a[x].end());
  } else {
    // 시계
    rotate(a[x].rbegin(), a[x].rbegin() + k, a[x].rend());
  }
  return;
}
void print() {
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < M; j++) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
}

void a_avg() {
  // cout << "avg 구하기\n";
  int sum = 0, cnt = 0;

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < M; j++) {
      if (a[i][j]) {
        sum += a[i][j];
        cnt++;
      }
    }
  }
  if (cnt == 0) return;
  double avg = (double)sum / (double)cnt;
  // cout << "avg : " << avg << '\n';

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < M; j++) {
      if (a[i][j] && a[i][j] > avg) {
        a[i][j] -= 1;
      } else if (a[i][j] && a[i][j] < avg) {
        a[i][j] += 1;
      }
    }
  }
}

void go(int y, int x, vector<pair<int, int>>& v) {
  visited[y][x] = 1;
  v.push_back({y, x});

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = (x + dx[i] + M) % M;

    if (ny <= 0 || ny > N || visited[ny][nx]) continue;
    if (a[y][x] == a[ny][nx]) {
      go(ny, nx, v);
    }
  }
  return;
}

void delete_num() {
  memset(visited, 0, sizeof(visited));
  bool check = false;

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < M; j++) {
      vector<pair<int, int>> v;
      if (!visited[i][j] && a[i][j]) {
        go(i, j, v);
        if (v.size() <= 1)
          continue;
        else {
          check = true;
          for (pair<int, int> p : v) {
            a[p.first][p.second] = 0;
          }
        }
      }
    }
  }
  if (!check) {
    a_avg();
  }
  return;
}

int main() {
  cin >> N >> M >> T;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < M; j++) {
      int temp = 0;
      cin >> temp;
      a[i].push_back(temp);
    }
  }

  for (int i = 0; i < T; i++) {
    cin >> x >> d >> k;
    for (int j = x; j <= N; j += x) {
      _rotate(j, d, k);
    }
    delete_num();
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < M; j++) {
      ret += a[i][j];
    }
  }

  cout << ret;

  return 0;
}