#include <bits/stdc++.h>

using namespace std;

int n, temp, ret[500004];
stack<pair<int, int>> stk;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> temp;

    while (!stk.empty()) {
      if (stk.top().second < temp)
        stk.pop();
      else {
        ret[i] = stk.top().first;
        break;
      }
    }
    stk.push({i + 1, temp});
  }

  for (int i = 0; i < n; i++) {
    cout << ret[i] << ' ';
  }

  return 0;
}