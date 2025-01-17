#include <bits/stdc++.h>
using namespace std;

int n;
string s, temp;
char a[65][65];

bool check(int n, int y, int x) {
  char first_char = a[y][x];

  for (int i = y; i < y + n; i++) {
    for (int j = x; j < x + n; j++) {
      if (first_char != a[i][j]) return false;
    }
  }
  return true;
}

string go(int n, int y, int x) {
  string ret = "";

  // 확인하는 로직
  if (check(n, y, x) || n == 1) {
    ret += a[y][x];
    return ret;
  } else {
    ret += '(';
    ret += go(n / 2, y, x);
    ret += go(n / 2, y, x + n / 2);
    ret += go(n / 2, y + n / 2, x);
    ret += go(n / 2, y + n / 2, x + n / 2);
    ret += ')';
  }

  return ret;
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> temp;
    for (int j = 0; j < n; j++) {
      a[i][j] = temp[j];
    }
  }

  cout << go(n, 0, 0);

  return 0;
}