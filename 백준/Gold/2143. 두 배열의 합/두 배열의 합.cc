#include <bits/stdc++.h>
using namespace std;

long long T, n, m, ret, temp, a[1004], b[1004];
unordered_map<int, int> mp;

int main() {
  cin >> T >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  for (int i = 0; i < m; i++) cin >> b[i];

  for (int i = 0; i < m; i++) {
    int sum = 0;
    for (int j = i; j < m; j++) {
      sum += b[j];
      mp[sum]++;
    }
  }

  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += a[j];
      ret += mp[T - sum];
    }
  }

  cout << ret;

  return 0;
}