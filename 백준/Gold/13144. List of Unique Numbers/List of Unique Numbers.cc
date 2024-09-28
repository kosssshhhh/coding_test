#include <bits/stdc++.h>
using namespace std;

long long n, a[100004], cnt[100004], ret;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  int l = 0, h = 0;

  while (h < n) {
    if (!cnt[a[h]])
      cnt[a[h++]]++;
    else {
      ret += (h - l);
      cnt[a[l]]--;
      l++;
    }
  }
  ret += (long long)(h - l) * (h - l + 1) / 2;

  cout << ret;

  return 0;
}