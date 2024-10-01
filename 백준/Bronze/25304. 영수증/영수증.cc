#include <bits/stdc++.h>
using namespace std;

long long x, n, a, b, sum;

int main() {
  cin >> x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    sum += a * b;
  }
  if (x == sum)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}