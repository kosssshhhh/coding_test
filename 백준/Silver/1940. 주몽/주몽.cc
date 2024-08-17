#include <bits/stdc++.h>
using namespace std;

int n, ret;
long long m;
int arr[15004];

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      if (m == arr[i] + arr[j]) ret++;
    }

  cout << ret << '\n';
  return 0;
}