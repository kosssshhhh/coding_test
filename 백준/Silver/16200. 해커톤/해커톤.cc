#include <bits/stdc++.h>
using namespace std;

int n, ret, cnt, limit, a[100004];

bool cmp(int a, int b) { return a > b; }

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a, a + n);

  for (int i = 0; i < n; i++) {
    if (cnt == 0) limit = a[i];
    cnt++;

    if (cnt == limit) {
      cnt = 0;
      ret++;
    }
  }

  if (cnt) ret++;

  cout << ret;

  return 0;
}