#include <bits/stdc++.h>
using namespace std;

const int n = 18;
double a, b, dp[20][20][20];
bool isPrime[20];

void che() {
  fill(isPrime, isPrime + 20, 1);
  isPrime[0] = 0;
  isPrime[1] = 0;
  for (int i = 2; i <= 20; i++) {
    for (int j = i + i; j <= 20; j += i) {
      isPrime[j] = 0;
    }
  }
}

double go(int idx, int x, int y) {
  if (idx == n) return isPrime[x] || isPrime[y] ? 1.0 : 0.0;
  double &ret = dp[idx][x][y];
  if (ret > -0.5) return ret;

  ret = 0.0;
  ret += go(idx + 1, x + 1, y) * a * (1 - b);
  ret += go(idx + 1, x + 1, y + 1) * a * b;
  ret += go(idx + 1, x, y + 1) * (1 - a) * b;
  ret += go(idx + 1, x, y) * (1 - a) * (1 - b);

  return ret;
}

int main() {
  cin >> a >> b;
  a = a * 0.01;
  b = b * 0.01;

  che();
  memset(dp, -1, sizeof(dp));
  cout << go(0, 0, 0);

  return 0;
}

// DP, 확률 == 경우의 수
