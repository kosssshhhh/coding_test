#include <bits/stdc++.h>
using namespace std;

int T, n, cnt_5;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> T;

  for (int t = 0; t < T; t++) {
    cin >> n;

    cnt_5 = 0;

    for (int i = 5; i <= n; i *= 5) {
      cnt_5 += n / i;
    }
    cout << cnt_5 << '\n';
  }

  return 0;
}

// 최대범위 10억 브루트포스 x
// 결국 0의 개수는 10의 개수
// 10의 개수는 2와 5의 개수
// n의 승수의 개수