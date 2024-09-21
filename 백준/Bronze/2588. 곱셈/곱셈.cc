#include <bits/stdc++.h>
using namespace std;

int a;
string b;

int main() {
  cin >> a >> b;

  for (int i = 2; i >= 0; i--) {
    cout << a * (b[i] - '0') << '\n';
  }
  cout << a * atoi(b.c_str());

  return 0;
}