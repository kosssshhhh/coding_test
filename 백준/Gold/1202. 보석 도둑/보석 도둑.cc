#include <bits/stdc++.h>
using namespace std;

int n, k, c;

long long ret;

int main() {
  cin >> n >> k;
  vector<pair<int, int>> v1(n);
  for (int i = 0; i < n; i++) cin >> v1[i].first >> v1[i].second;

  vector<int> pack(k);
  for (int i = 0; i < k; i++) cin >> pack[i];

  sort(v1.begin(), v1.end());
  sort(pack.begin(), pack.end());

  priority_queue<int> pq;

  int i = 0;
  for (int pack_v : pack) {
    while (i < n && v1[i].first <= pack_v) {
      pq.push(v1[i++].second);
    }
    if (pq.size()) {  // pq의 사이즈 확인하는 로직 필수
      ret += pq.top();
      pq.pop();
    }
  }

  cout << ret;

  return 0;
}

// 그리디, 정렬, PQ
// 보석과 가방 둘다 오름차순 정렬
// 보석이 가방에 들어갈 수 있으면, 보석가격 PQ push
// 그리고 가방에 제일 큰거 넣음