#include <bits/stdc++.h>
using namespace std;

int n, m, ret;

bool check(int val, vector<int> &v) {
  int lo = 0, hi = v.size();

  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    if (val == v[mid]) {
      return true;
    } else if (val < v[mid]) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  return false;
}

int main() {
  cin >> n >> m;
  vector<int> a(n), b(m);

  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  for (int i = 0; i < n; i++) {
    if (check(a[i], b)) {
      continue;
    } else {
      ret++;
    }
  }

  for (int i = 0; i < m; i++) {
    if (check(b[i], a)) {
      continue;
    } else {
      ret++;
    }
  }

  cout << ret;
  return 0;
}