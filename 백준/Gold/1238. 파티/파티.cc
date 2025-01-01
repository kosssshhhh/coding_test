#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m, x, ret;
int dist[1004];
vector<pair<int, int>> adj[1004];

void dijkstra(int start) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  dist[start] = 0;

  pq.push({0, start});

  while (pq.size()) {
    int here_cost = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (dist[u] != here_cost) continue;

    for (auto there : adj[u]) {
      int new_cost = here_cost + there.first;
      if (new_cost < dist[there.second]) {
        dist[there.second] = new_cost;
        pq.push({new_cost, there.second});
      }
    }
  }
}

int main() {
  cin >> n >> m >> x;

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
  }

  for (int i = 1; i <= n; i++) {
    if (i == x) continue;
    fill(dist, dist + 1004, INF);

    int mx = 0;

    dijkstra(i);  // 파티장으로 이동
    mx += dist[x];

    fill(dist, dist + 1004, INF);
    dijkstra(x);
    mx += dist[i];

    ret = max(mx, ret);
  }

  cout << ret;

  return 0;
}