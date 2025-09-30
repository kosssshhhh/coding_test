#include <bits/stdc++.h>
using namespace std;

int T, n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;

  while (T--) {
    int ret = 0;
    cin >> n;
    for (int i = 5; i <= n; i *= 5) {
      ret += n / i;
    }
    cout << ret << '\n';
  }

  return 0;
}