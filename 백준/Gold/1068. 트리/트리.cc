#include <bits/stdc++.h>
using namespace std;

int n, m, root, ret;
vector<int> adj[50];

void go(int u) {
  if (u == m) return;
  int cnt = 0;
  for (int v : adj[u]) {
    if (v == m) continue;
    go(v);
    cnt++;
  }

  if (cnt == 0) ret++;
}

int main() {
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

  go(root);

  cout << ret;

  return 0;
}