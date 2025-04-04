#include <bits/stdc++.h>
using namespace std;

int N, temp, mx, ret;
vector<int> v;

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    v.push_back(temp);
  }

  reverse(v.begin(), v.end());

  for (int a : v) {
    if (mx < a) {
      ret++;
      mx = a;
    }
  }

  cout << ret;

  return 0;
}