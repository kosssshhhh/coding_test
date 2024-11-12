#include <bits/stdc++.h>
using namespace std;

int n;
double a, sum = 1.0, ret = -1;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    sum *= a;

    ret = max(sum, ret);
    if (sum < a) {
      sum = a;
      ret = max(sum, ret);
    }
  }

  cout << fixed << setprecision(3) << ret;

  return 0;
}