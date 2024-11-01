#include <bits/stdc++.h>
using namespace std;

int n, m, res = 987654321;
int a[300000];

bool search(int val) {
  int ret = 0;
  for (int i = 0; i < m; i++) {
    ret += a[i] / val;
    if (a[i] % val) ret++;
  }
  return ret <= n;
}

int main() {
  cin >> n >> m;

  int left = 1, right = 0, mid;

  for (int i = 0; i < m; i++) {
    cin >> a[i];
    right = max(right, a[i]);
  }

  while (left <= right) {
    mid = (left + right) / 2;

    if (search(mid)) {
      res = min(res, mid);
      right = mid - 1;
    } else {
      // ret > n 이므로 mid 값보다 큰쪽으로 가야함
      left = mid + 1;
    }
  }
  cout << res;

  return 0;
}

// 이분탐색
// 이분탐색은 최적화(최대, 최소) 문제를 결정 문제로 바꿀 수 있음