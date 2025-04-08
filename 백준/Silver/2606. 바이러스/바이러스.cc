#include <bits/stdc++.h>
using namespace std;

int n, m, from, to, visited[104];
vector<int> adj[104];

int dfs(int here) {
  visited[here] = 1;
  int ret = 0;

  for (int there : adj[here]) {
    if (visited[there]) continue;

    ret += 1 + dfs(there);
  }

  return ret;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> from >> to;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }

  cout << dfs(1);

  return 0;
}