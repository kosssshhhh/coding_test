#include <bits/stdc++.h>
using namespace std;

int n, s, e, m, visited[104], candi[104], a, b, c, ok;
vector<pair<int, int>> adj[104];
long long dist[104], cost[104];
const long long INF = 1e18;
queue<int> q;

int main() {
  cin >> n >> s >> e >> m;

  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }

  for (int i = 0; i < n; i++) {
    cin >> cost[i];
  }

  fill(dist, dist + 104, -INF);
  dist[s] = cost[s];

  // 벨만포드
  for (int i = 0; i < n; i++) {
    for (int here = 0; here < n; here++) {
      for (pair<int, int> there : adj[here]) {
        int _dist = there.second;
        int _there = there.first;
        if (dist[here] != -INF &&
            dist[here] + cost[_there] - _dist > dist[_there]) {
          dist[_there] = dist[here] + cost[_there] - _dist;
          if (i == n - 1) q.push(here);
        }
      }
    }
  }

  while (q.size()) {
    int here = q.front();
    q.pop();

    for (pair<int, int> there : adj[here]) {
      if (there.first == e) {
        ok = 1;
        break;
      }
      if (!visited[there.first]) {
        visited[there.first] = 1;
        q.push(there.first);
      }
    }
    if (ok) break;
  }
  if (dist[e] == -INF)
    cout << "gg";
  else if (ok)
    cout << "Gee";
  else
    cout << dist[e];

  return 0;
}

// 벨만포드 - 음의 사이클 존재