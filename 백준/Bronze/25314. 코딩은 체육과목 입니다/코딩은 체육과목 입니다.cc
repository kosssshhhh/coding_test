#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
  cin >> n;

  for (int i = 1; i < n; i += 4) {
    s += "long ";
  }
  s += "int";

  cout << s;

  return 0;
}