#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b, c;

long long func(ll a, ll b) {
  if (b == 1) return a % c;

  // if (b % 2 == 1) {
  //   b -= 1;
  //   a = a * a % c;
  // }

  ll ret = func(a, b / 2);
  ret = (ret * ret) % c;
  if (b % 2) ret = (ret * a) % c;
  return ret;
  // return (func(a, b / 2) * func(a, b / 2)) % c;
}

int main() {
  cin >> a >> b >> c;

  cout << func(a, b) << '\n';

  return 0;
}