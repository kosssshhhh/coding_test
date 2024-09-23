#include <bits/stdc++.h>
using namespace std;

int n, d, p, sum, ret;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
  cin >> n;
  vector<pair<int, int>> v(n);  // <날짜, 돈>
  for (int i = 0; i < n; i++) cin >> v[i].second >> v[i].first;

  sort(v.begin(), v.end());  // 날짜로 정렬

  for (int i = 0; i < n; i++) {
    pq.push(v[i].second);
    if (pq.size() > v[i].first) {
      pq.pop();
    }
  }

  while (!pq.empty()) {
    ret += pq.top();
    pq.pop();
  }

  cout << ret << '\n';
  return 0;
}

// 그리디, 우선순위 큐, 정렬
// 최대를 만드는건 최소를 작게하거나, 최대를 크게 하는 것