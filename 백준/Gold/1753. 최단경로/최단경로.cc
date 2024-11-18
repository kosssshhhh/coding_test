#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<pair<int, int>> adj[20004];  // 그래프의 인접 리시트 표현 (정점, 가중치)
vector<int> dist(20004, INF);  // 최단 거리 배열

void dijkstra(int start) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  dist[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {
    int here_cost = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    // cout << "PQTOP\n";
    // cout << u << '\n';

    // 느긋한 삭제
    if (dist[u] != here_cost) continue;

    for (auto there : adj[u]) {
      int new_cost = here_cost + there.first;
      if (new_cost < dist[there.second]) {
        dist[there.second] = new_cost;
        // cout << there.second << " : " << new_cost << '\n';
        pq.push({new_cost, there.second});
      }
    }
  }
}

int main() {
  int n, m, start;
  cin >> n >> m >> start;

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
  }

  dijkstra(start);

  for (int i = 1; i <= n; i++) {
    if (dist[i] == INF)
      cout << "INF\n";
    else
      cout << dist[i] << '\n';
  }

  return 0;
}