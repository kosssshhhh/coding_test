#include <bits/stdc++.h>
using namespace std;

int h, w, visited[104][104];
string s;

int main() {
  cin >> h >> w;

  memset(visited, -1, sizeof(visited));

  for (int i = 0; i < h; i++) {
    cin >> s;
    for (int j = 0; j < w; j++) {
      if (s[j] == 'c') {
        visited[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < h; i++) {
    bool flag = false;
    int t = 0;
    for (int j = 0; j < w; j++) {
      if (visited[i][j] == 0) {
        t = 0;
        flag = true;
      }
      if (flag) {
        visited[i][j] = t;
        t++;
      }
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << visited[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}