#include <bits/stdc++.h>
using namespace std;

int t, n, cnt_2, cnt_5;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> n;
    cnt_2 = 0;
    cnt_5 = 0;

    for (int j = 2; j <= n; j *= 2) cnt_2 += n / j;
    for (int k = 5; k <= n; k *= 5) cnt_5 += n / k;
    cout << min(cnt_2, cnt_5) << '\n';
  }

  return 0;
}