#include <bits/stdc++.h>
using namespace std;

int n, sum;
string s;

int main() {
  cin >> n;
  cin >> s;

  for (int i = 0; i < n; i++) {
    sum += s[i] - '0';
  }
  cout << sum;

  return 0;
}