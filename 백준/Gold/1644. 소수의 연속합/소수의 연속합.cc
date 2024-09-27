#include <bits/stdc++.h>
using namespace std;

bool che[4000001];
int n, a[2000001], p, sum, lo, hi, ret;

int main() {
  scanf("%d", &n);
  // 에라토스테네스의 체
  for (int i = 2; i <= n; i++) {
    if (che[i]) continue;
    for (int j = 2 * i; j <= n; j += i) {
      che[j] = 1;
    }
  }

  // 소수 배열 만들기
  for (int i = 2; i <= n; i++) {
    if (!che[i]) a[p++] = i;
  }

  // 투포인터
  while (1) {
    if (sum >= n)
      sum -= a[lo++];
    else if (hi == p)
      break;
    else
      sum += a[hi++];

    if (sum == n) ret++;
  }
  cout << ret;

  return 0;
}

// 투포인터, 에라토스테네스의 체
// 에라 체를 통해 소수 구하기
// 구한 소수 배열로 투포인터 low, high 지정해서 구간합