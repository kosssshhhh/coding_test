#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, visited[104];
vector<int> adj[104];

int dfs(int here) {
  visited[here] = 1;

  int ret = 0;
  // cout << "here: " << here << '\n';

  for (int there : adj[here]) {
    if (visited[there]) continue;

    ret += dfs(there) + 1;
  }
  return ret;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  cout << dfs(1);

  return 0;
}

// dfs cnt