#include <bits/stdc++.h>
using namespace std;

int num, cnt[32];

int main() {
  for (int i = 0; i < 28; i++) {
    cin >> num;
    cnt[num] = 1;
  }
  for (int i = 1; i <= 30; i++) {
    if (!cnt[i]) cout << i << '\n';
  }

  return 0;
}