#include <bits/stdc++.h>
using namespace std;

int n, len, lis[104];
pair<int, int> a[104];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }

  sort(a, a + n);

  for (int i = 0; i < n; i++) {
    auto pos = lower_bound(lis, lis + len, a[i].second);
    if (*pos == 0) len++;
    *pos = a[i].second;
  }

  cout << n - len;

  return 0;
}

// 최대증가수열
// A전봇대를 sort하고 봤더니 B 전봇대를 Lis로 뽑으면 정답
