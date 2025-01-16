#include <bits/stdc++.h>
using namespace std;

int a[6] = {1, 1, 2, 2, 2, 8};
int temp;

int main() {
  for (int i = 0; i < 6; i++) {
    cin >> temp;
    cout << a[i] - temp << ' ';
  }

  return 0;
}