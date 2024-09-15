#include <bits/stdc++.h>
using namespace std;

int m, n;
string str;

int a;

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> m;

  for (int i = 0; i < m; i++) {
    cin >> str;

    if (str == "add") {
      cin >> n;

      a |= (1 << (n - 1));
    } else if (str == "remove") {
      cin >> n;

      a &= ~(1 << (n - 1));
    } else if (str == "check") {
      cin >> n;

      if (a & (1 << (n - 1)))
        cout << 1 << '\n';
      else
        cout << 0 << '\n';
    } else if (str == "toggle") {
      cin >> n;

      a ^= (1 << (n - 1));
    } else if (str == "all") {
      a = (1 << 20) - 1;

    } else if (str == "empty") {
      a = 0;
    }
  }

  return 0;
}
