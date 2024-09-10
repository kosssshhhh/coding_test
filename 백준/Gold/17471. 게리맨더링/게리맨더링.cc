#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, m, temp, ret = INF, a[12], visited[12], comp[12];
vector<int> adj[12];

pair<int, int> dfs(int here, int value) {
  visited[here] = 1;
  pair<int, int> ret = {1, a[here - 1]};

  for (int there : adj[here]) {
    if (visited[there]) continue;
    if (comp[there] != value) continue;

    pair<int, int> _temp = dfs(there, value);

    ret.first += _temp.first;
    ret.second += _temp.second;
  }
  return ret;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    cin >> m;
    for (int j = 0; j < m; j++) {
      cin >> temp;
      adj[i].push_back(temp);
      adj[temp].push_back(i);
    }
  }

  for (int i = 1; i < (1 << n) - 1;
       i++) {  // 무조건 두 개의 선거구로 나누어야하기 때문에 범위 설정
    fill(visited, visited + 12, 0);
    fill(comp, comp + 12, 0);
    int idx1 = -1, idx2 = -1;

    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        comp[j + 1] = 1;
        idx1 = j + 1;
      } else {
        idx2 = j + 1;
      }
    }
    // 0구역과 1구역으로 나누어 dfs (Connected Component)
    pair<int, int> ret1 = dfs(idx1, 1);
    pair<int, int> ret2 = dfs(idx2, 0);

    if (ret1.first + ret2.first ==
        n) {  // 두 선거구에서 방문한 지점이 전체 선거구에 개수과 같으면
      ret = min(ret, abs(ret1.second - ret2.second));
    }
  }

  cout << (ret == INF ? -1 : ret) << '\n';

  return 0;
}

// 모든 경우의 수 (비트마스킹)
// 그래프를 두개의 구역으로 나누기
// Connected Component를 순회하여 탐색한 노드의 수가 전체 노드 수랑 같은지 확인
// pair<int, int> 형의 DFS 구현