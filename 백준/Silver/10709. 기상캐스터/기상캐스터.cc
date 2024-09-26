#include <bits/stdc++.h>
using namespace std;

int H, W;
string temp;
char a[104][104];
int b[104][104];

int main() {
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    cin >> temp;
    for (int j = 0; j < W; j++) {
      a[i][j] = temp[j];
    }
  }

  for (int i = 0; i < H; i++) {
    int cnt = 0;

    for (int j = 0; j < W; j++) {
      if (a[i][j] == 'c') {
        cnt = 0;
        b[i][j] = cnt;
        cnt++;
      } else if (a[i][j] == '.' && cnt != 0) {
        b[i][j] = cnt;
        cnt++;
      } else if (a[i][j] == '.' && cnt == 0) {
        b[i][j] = -1;
      }
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << b[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}