#include <bits/stdc++.h>
using namespace std;

int n, ret;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
  // input
  cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

  sort(v.begin(), v.end());

  for (pair<int, int> a : v) {
    pq.push(a.second);
    if (pq.size() > a.first) {
      pq.pop();
    }
  }
  while (!pq.empty()) {
    ret += pq.top();
    pq.pop();
  }

  cout << ret;
  return 0;
}