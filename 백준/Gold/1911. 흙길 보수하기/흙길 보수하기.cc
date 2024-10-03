#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, l, idx, b, ret;
ll s, e;
vector<pair<ll, ll>> v;

int main() {
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    cin >> s >> e;
    v.push_back({s, e});
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < n; i++) {
    int start = v[i].first;
    int end = v[i].second;

    if (end <= idx) continue;
    if (idx < start) {
      b = (end - start) / l + ((end - start) % l ? 1 : 0);
      idx = start + b * l;
    } else {
      b = (end - idx) / l + ((end - idx) % l ? 1 : 0);
      idx = idx + b * l;
    }
    ret += b;
  }
  cout << ret;

  return 0;
}

// 그리디, 정렬
// start, end, idx 세 변수의 위치에 따라 조건 생각하기