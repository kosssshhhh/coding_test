#include <bits/stdc++.h>
using namespace std;

int N, temp, mn = 987654321, mx = -1000004;
vector<int> v;

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    mx = max(temp, mx);
    mn = min(temp, mn);
  }

  cout << mn << ' ' << mx;
  return 0;
}