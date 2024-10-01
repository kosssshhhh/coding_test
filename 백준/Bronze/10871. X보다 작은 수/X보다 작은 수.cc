#include <bits/stdc++.h>
using namespace std;

int N, X, temp;
vector<int> v;

int main() {
  cin >> N >> X;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    if (temp < X) v.push_back(temp);
  }
  for (int a : v) cout << a << ' ';

  return 0;
}