#include <bits/stdc++.h>
using namespace std;

int n, m, r, a, b, d, visited[100004], ret[100004];
vector<int> adj[100004];

void dfs(int here) {
  visited[here] = 1;
  ret[here] = ++d;

  for (int there : adj[here]) {
    if (visited[there]) continue;
    dfs(there);
  }

  return;
}

int main() {
  cin >> n >> m >> r;

  for (int i = 0; i < m; i++) {
    cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    sort(adj[i].begin(), adj[i].end());
  }
  dfs(r);

  for (int i = 1; i <= n; i++) {
    cout << ret[i] << '\n';
  }

  return 0;
}