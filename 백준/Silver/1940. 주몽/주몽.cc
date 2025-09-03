#include <bits/stdc++.h>
using namespace std;

int n, m, temp, ret;
vector<int> v;

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> temp;
    v.push_back(temp);
  }

  sort(v.begin(), v.end());

  int lo = 0, hi = v.size() - 1;

  while (lo < hi) {
    int sum = v[lo] + v[hi];
    if (sum == m) {
      ret++;
      lo++, hi--;
    } else if (sum > m) {
      hi--;
    } else {
      lo++;
    }
  }

  cout << ret;

  return 0;
}