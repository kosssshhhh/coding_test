#include <bits/stdc++.h>
using namespace std;

int n, c, a;
map<int, int> cnt;
map<int, int> first;

vector<int> v;
bool cmp(int a, int b) {
  if (cnt[a] == cnt[b]) return first[a] < first[b];
  return cnt[a] > cnt[b];
}

int main() {
  cin >> n >> c;

  for (int i = 0; i < n; i++) {
    cin >> a;
    cnt[a]++;
    if (!first[a]) first[a] = i + 1;
    v.push_back(a);
  }

  sort(v.begin(), v.end(), cmp);

  for (int a : v) cout << a << ' ';

  return 0;
}

// 빈도 정렬
// 등장 횟수, 먼저 나온것
// 두개의 자료구조에 각각 저장?