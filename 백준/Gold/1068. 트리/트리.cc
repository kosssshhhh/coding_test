#include <bits/stdc++.h>
using namespace std;

int n, temp, root, r, ret;
vector<int> adj[101];

int dfs(int here) {
  int ret = 0;
  int child = 0;

  for (int there : adj[here]) {
    if (there == r) continue;
    ret += dfs(there);
    child++;
  }
  if (child == 0) return 1;
  return ret;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    if (temp == -1)
      root = i;
    else
      adj[temp].push_back(i);
  }
  cin >> r;

  if (r == root) {
    cout << 0 << '\n';
    return 0;
  }
  ret = dfs(root);

  cout << ret;
  return 0;
}

// 트리 순회는 무조건 root 노드부터
// adj 만들어서 해결