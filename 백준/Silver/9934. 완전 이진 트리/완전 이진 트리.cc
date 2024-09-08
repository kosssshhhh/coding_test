#include <bits/stdc++.h>
using namespace std;

int k, a[1030];
vector<vector<int>> v;

void go(int idx, vector<int>& arr) {
  if (arr.size() == 1) {
    v[idx].push_back(arr[0]);
    return;
  }

  int mid = arr.size() / 2;

  v[idx].push_back(arr[mid]);
  vector<int> left(arr.begin(), arr.begin() + mid);
  vector<int> right(arr.begin() + mid + 1, arr.end());

  go(idx + 1, left);
  go(idx + 1, right);
}

int main() {
  cin >> k;
  int n = pow(2, k) - 1;
  for (int i = 0; i < n; i++) cin >> a[i];

  v.resize(k);

  vector<int> arr(a, a + n);
  go(0, arr);

  for (vector<int> i : v) {
    for (int j : i) {
      cout << j << ' ';
    }
    cout << '\n';
  }
  return 0;
}

// left, right 기반 재귀함수
// BFS 순서로 다시 출력해주어야함
