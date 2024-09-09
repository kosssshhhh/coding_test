#include <bits/stdc++.h>
using namespace std;
#define prev aaa

bool flag = true;
int n;
string temp;
char a[68][68];
char prev;

string quard(int y, int x, int size) {
  string ret = "";
  flag = true;

  for (int i = y; i < y + size; i++) {
    for (int j = x; j < x + size; j++) {
      if (i == y && j == x) {
        prev = a[i][j];
      } else {
        if (a[i][j] != prev) {
          flag = false;
          break;
        }
      }
      prev = a[i][j];
    }
    if (!flag) break;
  }

  if (flag) {
    ret += a[y][x];
  } else {
    ret += '(';
    ret += quard(y, x, size / 2);
    ret += quard(y, x + size / 2, size / 2);
    ret += quard(y + size / 2, x, size / 2);
    ret += quard(y + size / 2, x + size / 2, size / 2);
    ret += ')';
  }
  return ret;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    for (int j = 0; j < n; j++) a[i][j] = temp[j];
  }

  cout << quard(0, 0, n) << '\n';

  return 0;
}