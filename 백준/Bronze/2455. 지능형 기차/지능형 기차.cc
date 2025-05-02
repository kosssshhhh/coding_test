#include <bits/stdc++.h>
using namespace std;

int out, in, curr, mx;

int main() {
  for (int i = 0; i < 4; i++) {
    cin >> out >> in;
    curr += in - out;
    mx = max(mx, curr);
  }

  cout << mx;
  return 0;
}