#include <bits/stdc++.h>
using namespace std;

int N, K, psum[100004], temp, ret = -10000000;

int main() {
  cin >> N >> K;

  for (int i = 1; i <= N; i++) {
    cin >> temp;
    psum[i] = psum[i - 1] + temp;
  }

  for (int i = K; i <= N; i++) {
    ret = max(ret, psum[i] - psum[i - K]);
  }

  cout << ret;

  return 0;
}

// 누적합(psum)을 이용한 풀이
// 구간합 같은 경우에는 누적합 배열을 사용하여 푸는 것이 좋다!