#include <bits/stdc++.h>
using namespace std;
#define y1 aaa

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int n, m, y1, x1, cnt;
string temp;
char a[1504][1504];
int visited_swan[1504][1504];
int visited[1504][1504];

queue<pair<int, int>> swanQ, waterQ, swan_tempQ, water_tempQ;

void Qclear(queue<pair<int, int>> &q) {
  queue<pair<int, int>> empty;
  swap(q, empty);
}

bool move_swan() {
  while (swanQ.size()) {
    int y = swanQ.front().first;
    int x = swanQ.front().second;
    swanQ.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited_swan[ny][nx])
        continue;
      visited_swan[ny][nx] = 1;
      if (a[ny][nx] == '.')
        swanQ.push({ny, nx});
      else if (a[ny][nx] == 'X')
        swan_tempQ.push({ny, nx});
      else if (a[ny][nx] == 'L')
        return true;
    }
  }
  return false;
}

void water_melting() {
  while (waterQ.size()) {
    int y = waterQ.front().first;
    int x = waterQ.front().second;
    waterQ.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
      if (a[ny][nx] == 'X') {
        visited[ny][nx] = 1;
        water_tempQ.push({ny, nx});
        a[ny][nx] = '.';
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    for (int j = 0; j < m; j++) {
      a[i][j] = temp[j];
      if (temp[j] == 'L') {
        y1 = i, x1 = j;
      }
      if (temp[j] == '.' || temp[j] == 'L') {
        visited[i][j] = 1;
        waterQ.push({i, j});
      }
    }
  }

  swanQ.push({y1, x1});
  visited_swan[y1][x1] = 1;
  while (true) {
    if (move_swan()) break;
    water_melting();
    waterQ = water_tempQ;
    swanQ = swan_tempQ;

    Qclear(water_tempQ);
    Qclear(swan_tempQ);

    cnt++;
  }

  cout << cnt;
  return 0;
}

// 처음에 DFS로 풀려했으나 시간 초과
// BFS로 초기에 물 위치 정보 queue에 넣어서 해당 위치만 탐색
// Queue를 두개 사용하여 백조와 물 따로 탐색
// temp Queue를 사용하여 이전 상태의 위치 정보 가져와서 불필요한 탐색 제거