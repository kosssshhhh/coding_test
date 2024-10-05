#include <bits/stdc++.h>
using namespace std;

double n, mx, score, sum, a[1004];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> score;
    a[i] = score;
    mx = max(score, mx);
  }

  for (int i = 0; i < n; i++) {
    a[i] = a[i] / mx * 100;
    sum += a[i];
  }
  cout << (sum / n);

  return 0;
}