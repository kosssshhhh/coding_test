#include <bits/stdc++.h>
using namespace std;

bool mode = false, flag = false;
int t, n, x;
string p, arr;
deque<int> D;

int main() {
  cin >> t;

  while (t--) {
    flag = false;
    mode = false;
    D.clear();
    arr.clear();
    p.clear();

    cin >> p >> n >> arr;

    for (char c : arr) {
      if (c == '[') continue;
      if (c >= '0' && c <= '9')
        x = x * 10 + c - '0';
      else {
        if (x > 0) D.push_back(x);
        x = 0;
      }
    }

    for (char c : p) {
      if (c == 'R') {
        mode = !mode;
      } else if (c == 'D') {
        if (D.size() == 0) {
          flag = true;
          break;
        }
        if (mode) {
          D.pop_back();
        } else {
          D.pop_front();
        }
      }
    }
    if (flag) {
      cout << "error\n";
      continue;
    } else {
      if (mode) reverse(D.begin(), D.end());

      cout << '[';
      for (int i = 0; i < D.size(); i++) {
        cout << D[i];
        if (i < D.size() - 1) cout << ",";
      }
      cout << "]\n";
    }
  }

  return 0;
}