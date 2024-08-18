#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b, c;

long long func(ll a, ll b) {
  if (b == 0) return 1;
  if (b == 1) return a % c;

  ll ret = func(a, b / 2);

  ret = (ret * ret) % c;

  if (b % 2) ret = (ret * a) % c;

  return ret;
}

int main() {
  cin >> a >> b >> c;

  cout << func(a, b) << '\n';

  return 0;
}