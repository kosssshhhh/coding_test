#include <bits/stdc++.h>
using namespace std;

int n, cnt, num = 666;

int main() {
  cin >> n;

  while (true) {
    if (to_string(num).find("666") != string::npos) {
      cnt++;
      if (cnt == n) {
        cout << num;
        break;
      }
    }
    num++;
  }

  return 0;
}