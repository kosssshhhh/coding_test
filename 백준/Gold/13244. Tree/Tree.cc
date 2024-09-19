#include <bits/stdc++.h>
using namespace std;

int t, n, m, x, y, cnt;
int visited[1004];
vector<int> adj[1004];

void dfs(int here) {
  visited[here] = 1;
  for (int there : adj[here]) {
    if (visited[there]) continue;
    dfs(there);
  }
}

int main() {
  cin >> t;

  for (int k = 0; k < t; k++) {
    for (int i = 0; i < 1004; i++) adj[i].clear();
    fill(visited, visited + 1004, 0);
    cnt = 0;
    cin >> n >> m;
    for (int a = 0; a < m; a++) {
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
      if (visited[i]) continue;
      dfs(i);
      cnt++;
    }

    if (cnt == 1 && n - 1 == m)
      cout << "tree\n";
    else
      cout << "graph\n";
  }
  return 0;
}

// Tree의 이해
// 노드의 개수는 간선의 개수 - 1
// 한번의 dfs로 모든 트리 순회 가능
// 트리 구현할 때 꼭 양방향 간선으로 구현