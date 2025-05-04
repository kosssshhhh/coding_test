#include <bits/stdc++.h>
using namespace std;

int temp, ret;
vector<int> v;

void go(int idx, vector<int> vv) {
  if (idx > 9) return;
  if (vv.size() == 7) {
    int sum = 0;
    for (int a : vv) {
      if (a == 0) return;
      sum += a;
    }

    if (sum == 100)
      for (int a : vv) cout << a << '\n';
    return;
  }

  vv.push_back(v[idx]);
  go(idx + 1, vv);
  vv.pop_back();

  go(idx + 1, vv);

  return;
}

int main() {
  for (int i = 0; i < 9; i++) {
    cin >> temp;
    v.push_back(temp);
  }

  vector<int> vv;
  go(0, vv);

  return 0;
}