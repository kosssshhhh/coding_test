#include <bits/stdc++.h>
using namespace std;

int n = 9, k = 2;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> v(9);
  int sum = 0;

  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (sum - v[i] - v[j] == 100) {
        for (int k = 0; k < n; k++) {
          if (k != i && k != j) cout << v[k] << '\n';
        }
        return 0; // 원하는 결과를 찾으면 프로그램 종료
      }
    }
  }

  return 0;
}