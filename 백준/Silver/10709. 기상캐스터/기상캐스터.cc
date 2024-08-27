#include <bits/stdc++.h>
using namespace std;

string temp;
int h, w;
char a[104][104];
int ret[104][104];
int cnt;

int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> temp;
    for (int j = 0; j < w; j++) {
      a[i][j] = temp[j];
    }
  }

  for (int i = 0; i < h; i++) {
    int cnt;
    bool flag = false;

    for (int j = 0; j < w; j++) {
      if (!flag) ret[i][j] = -1;
      if (a[i][j] == 'c') {
        flag = true;
        cnt = 0;
        ret[i][j] = cnt;
      }
      if (flag && a[i][j] == '.') {
        cnt++;
        ret[i][j] = cnt;
      }
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << ret[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}