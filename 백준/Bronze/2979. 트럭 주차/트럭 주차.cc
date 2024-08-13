#include <bits/stdc++.h>
using namespace std;

int A, B, C;
int first, last;
int min_t = 101, max_t = 0;
int sum = 0;
vector<pair<int, int>> v;

int main() {
  cin >> A >> B >> C;
  for (int i = 0; i < 3; i++) {
    cin >> first >> last;

    v.push_back({first, last});
    if (min_t > first) min_t = first;
    if (max_t < last) max_t = last;
  }

  int cnt[max_t - min_t];  // cnt 배열 생성
  memset(cnt, 0, sizeof(cnt));

  for (pair<int, int> a : v) {
    for (int i = a.first - min_t; i < a.second - min_t; i++) {
      cnt[i]++;
    }
  }

  for (int i : cnt) {
    if (i == 3)
      sum += C * i;
    else if (i == 2)
      sum += B * i;
    else if (i == 1)
      sum += A * i;
  }

  cout << sum << '\n';

  // 1. min max 구하기
  // 2. 시간 배열 생성 (크기 = max - min)
  // 3. v 돌면서 0~max-min 까지 값 채우기
  // 4. sum 하는 로직

  return 0;
}