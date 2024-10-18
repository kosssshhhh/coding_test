#include <bits/stdc++.h>
using namespace std;

int n, m, v, a, b, visited[1004];
vector<int> adj[1004];

void dfs(int here) {
  visited[here] = 1;
  cout << here << ' ';

  for (int there : adj[here]) {
    if (visited[there]) continue;
    dfs(there);
  }
  return;
}

void bfs(int here) {
  queue<int> q;
  visited[here] = 1;
  q.push(here);

  while (q.size()) {
    int here = q.front();
    q.pop();

    cout << here << ' ';

    for (int there : adj[here]) {
      if (visited[there]) continue;
      visited[there] = 1;
      q.push(there);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> v;

  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    sort(adj[i].begin(), adj[i].end());
  }

  dfs(v);
  memset(visited, 0, sizeof(visited));
  cout << '\n';
  bfs(v);

  return 0;
}