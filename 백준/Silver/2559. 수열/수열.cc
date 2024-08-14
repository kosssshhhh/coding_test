#include <bits/stdc++.h>
using namespace std;

int N, K, sum = 0, smax = -100000;
int arr[100004];

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i <= N - K; i++) {
    sum = 0;
    for (int j = 0; j < K; j++) {
      sum += arr[i + j];
    }
    if (smax < sum) smax = sum;
  }

  cout << smax << '\n';

  return 0;
}