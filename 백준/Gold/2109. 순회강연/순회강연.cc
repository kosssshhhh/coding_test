#include <bits/stdc++.h>
using namespace std;

int n, ret;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({b, a});
  }

  // 날짜 오름차순
  sort(v.begin(), v.end());

  for (int i = 0; i < n; i++) {
    pq.push(v[i].second);
    if (pq.size() > v[i].first) pq.pop();
  }

  while (!pq.empty()) {
    ret += pq.top();
    pq.pop();
  }

  cout << ret;

  return 0;
}