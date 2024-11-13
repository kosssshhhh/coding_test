// vector로 받기
// a 기준으로 정렬
// b로 lis 구하기
// n - lis.length 답

#include <bits/stdc++.h>
using namespace std;

int n, ret, cnt[104];
pair<int, int> a[104];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }

  sort(a, a + n);
  fill(cnt, cnt + n, 1);

  for (int i = 0; i < n; i++) {
    int maxVal = 0;
    for (int j = 0; j < i; j++) {
      if (a[i].second > a[j].second && maxVal < cnt[j]) maxVal = cnt[j];
    }
    cnt[i] = maxVal + 1;
    ret = max(ret, cnt[i]);
  }

  cout << n - ret;

  return 0;
}
