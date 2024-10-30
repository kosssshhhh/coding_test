#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int temp;
int dp[100004][5][5];

vector<int> v;

int go(int here, int l, int r) {
  if (here == v.size()) {
    return 0;
  }

  int &ret = dp[here][l][r];
  if (ret != INF) return ret;
  ret = INF;

  int l_score = 0, r_score = 0;

  if (l == v[here]) {
    l_score = 1;
  } else if (l == 0) {
    l_score = 2;
  } else if ((abs(l - v[here]) % 2) == 1) {
    l_score = 3;
  } else {
    l_score = 4;
  }
  if (r == v[here]) {
    r_score = 1;
  } else if (r == 0) {
    r_score = 2;
  } else if ((abs(r - v[here]) % 2) == 1) {
    r_score = 3;
  } else {
    r_score = 4;
  }

  // 왼발로 갈때
  ret = min(ret, go(here + 1, v[here], r) + l_score);
  ret = min(ret, go(here + 1, l, v[here]) + r_score);

  return ret;
}

int main() {
  while (1) {
    cin >> temp;
    if (temp == 0) break;
    v.push_back(temp);
  }

  for (int i = 0; i < 100004; ++i) {
    for (int j = 0; j < 5; ++j) {
      for (int k = 0; k < 5; ++k) {
        dp[i][j][k] = INF;
      }
    }
  }

  cout << go(0, 0, 0);

  return 0;
}

// 무식하게: 2^10만 너무 큼
// DP 
// index, 왼발, 오른발 상태