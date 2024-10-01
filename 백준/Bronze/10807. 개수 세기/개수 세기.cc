#include <bits/stdc++.h>
using namespace std;

int n, a, b, cnt[204];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    cnt[a + 100]++;
  }
  cin >> b;
  cout << cnt[b + 100];

  return 0;
}