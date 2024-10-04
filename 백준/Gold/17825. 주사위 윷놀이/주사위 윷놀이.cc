#include <bits/stdc++.h>
using namespace std;

int horse[4], n = 10;
int v[14];
vector<int> adj[35];
int score[104];

void add(int here, int there) {
  adj[here].push_back(there);
  return;
}

void setMap() {
  for (int i = 0; i < 20; i++) add(i, i + 1);
  add(20, 100);
  // 왼
  add(5, 21);
  add(21, 22);
  add(22, 23);
  add(23, 24);
  // 아래
  add(10, 27);
  add(27, 28);
  add(28, 24);
  // 오른쪽
  add(15, 29);
  add(29, 30);
  add(30, 31);
  add(31, 24);
  // 위
  add(24, 25);
  add(25, 26);
  add(26, 20);

  for (int i = 1; i <= 20; i++) score[i] = 2 * i;
  score[21] = 13, score[22] = 16, score[23] = 19, score[24] = 25,
  score[25] = 30, score[26] = 35;
  score[27] = 22, score[28] = 24;
  score[29] = 28, score[30] = 27, score[31] = 26;
}

int move(int here, int cnt) {
  if (here == 100) return 100;
  if (adj[here].size() >= 2) {
    here = adj[here][1];
    cnt--;
  }
  if (cnt) {
    queue<int> q;
    q.push(here);
    int there;
    while (q.size()) {
      int x = q.front();
      q.pop();
      there = adj[x][0];
      q.push(there);
      if (there == 100) break;
      cnt--;
      if (cnt == 0) break;
    }
    return there;
  } else
    return here;
}

bool isHorse(int horse_idx, int idx) {
  if (horse_idx == 100) return false;
  for (int i = 0; i < 4; i++) {
    if (i == idx) continue;
    if (horse[i] == horse_idx) return true;
  }
  return false;
}

int go(int here) {
  if (here == n) return 0;
  int ret = 0;
  for (int i = 0; i < 4; i++) {
    int temp_idx = horse[i];
    int horse_idx = move(temp_idx, v[here]);
    if (isHorse(horse_idx, i)) continue;
    horse[i] = horse_idx;
    ret = max(ret, go(here + 1) + score[horse_idx]);
    horse[i] = temp_idx;
  }
  // cout << "ret : " << ret << "\n";
  return ret;
}

int main() {
  for (int i = 0; i < 10; i++) cin >> v[i];

  setMap();
  cout << go(0) << '\n';

  return 0;
}

// 빡구현, 완탐, 백트래킹, BFS
