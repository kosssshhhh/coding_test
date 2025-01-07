#include <bits/stdc++.h>
using namespace std;

int n, m, x, a, b, visited[100004];
vector<int> h[100004], l[100004];

int bfs(int here, vector<int> adj[]) {
  queue<int> q;
  visited[here] = 1;
  q.push(here);

  int ret = 0;
  while (q.size()) {
    int _here = q.front();
    q.pop();

    for (int there : adj[_here]) {
      if (visited[there]) continue;
      visited[there] = 1;
      q.push(there);
      ret++;
    }
  }
  return ret;
}

int main() {
  cin >> n >> m >> x;

  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    h[a].push_back(b);
    l[b].push_back(a);
  }

  int ret1 = bfs(x, l);
  fill(visited, visited + 100004, 0);

  int ret2 = bfs(x, h);

  cout << ret1 + 1 << ' ' << n - ret2 << '\n';

  return 0;
}