#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, cnt_2, cnt_5;

ll count_value(ll a, ll b) {
  ll ret = 0;
  ll temp = b;
  while (temp <= a) {
    ret += a / temp;

    temp *= b;
  }

  return ret;
}

int main() {
  cin >> n >> m;

  m = min(m, n - m);

  cnt_5 = count_value(n, 5) - count_value(m, 5) - count_value(n - m, 5);
  cnt_2 = count_value(n, 2) - count_value(m, 2) - count_value(n - m, 2);

  cout << min(cnt_5, cnt_2);

  return 0;
}