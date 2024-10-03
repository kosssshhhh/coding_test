#include <bits/stdc++.h>
using namespace std;

int T, K, idx, dir, ret, visited[1000];
string temp;
vector<pair<int, int>> v;
vector<string> gear;

void go(int idx, int dir) {
  if (idx < 0 || idx >= T) return;
  visited[idx] = 1;

  char l = gear[idx][6], r = gear[idx][2];

  if (dir == 1) {
    // 시계방향
    rotate(gear[idx].rbegin(), gear[idx].rbegin() + 1, gear[idx].rend());
  } else if (dir == -1) {
    // 반시계
    rotate(gear[idx].begin(), gear[idx].begin() + 1, gear[idx].end());
  }

  // 오른쪽 바퀴
  if (idx + 1 < T && !visited[idx + 1] && gear[idx + 1][6] != r) {
    go(idx + 1, dir * (-1));
  }
  if (idx - 1 >= 0 && !visited[idx - 1] && gear[idx - 1][2] != l) {
    go(idx - 1, dir * (-1));
  }

  return;
}

int main() {
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> temp;
    gear.push_back(temp);
  }

  cin >> K;
  for (int i = 0; i < K; i++) {
    memset(visited, 0, sizeof(visited));
    cin >> idx >> dir;
    idx--;

    go(idx, dir);
  }

  for (string s : gear) {
    if (s[0] == '1') ret++;
  }

  cout << ret;

  return 0;
}