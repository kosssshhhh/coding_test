#include <bits/stdc++.h>
using namespace std;

int n, m, ret, root, visited[50];
vector<int> adj[50];

void go(int u) {
  if (u == m) return;

  int children = 0;

  for (int v : adj[u]) {
    if (v == m) continue;
    children++;
    go(v);
  }

  if (children == 0) ret++;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    if (p == -1) {
      root = i;
    } else {
      adj[p].push_back(i);
    }
  }

  cin >> m;

  if (m == root) {
    cout << 0 << '\n';
    return 0;
  }

  go(root);

  cout << ret << '\n';

  return 0;
}