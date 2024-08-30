#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, ret, mx;
vector<int> adj[10004];
int visited[10004], dp[10004];

int go(int here) {
  int ret = 1;

  for (int there : adj[here]) {
    if (visited[there]) continue;
    visited[there] = 1;
    ret += go(there);
  }
  return ret;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    adj[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    memset(visited, 0, sizeof(visited));
    visited[i] = 1;
    dp[i] = go(i);
    mx = max(dp[i], mx);
  }

  for (int i = 0; i <= n; i++)
    if (mx == dp[i]) cout << i << ' ';

  return 0;
}