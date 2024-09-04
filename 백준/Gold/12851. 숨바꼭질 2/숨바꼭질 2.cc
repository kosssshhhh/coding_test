#include <bits/stdc++.h>
using namespace std;

int n, k, cnt, visited[100004];
queue<int> q;

int main() {
  cin >> n >> k;

  q.push(n);
  visited[n] = 1;

  while (q.size()) {
    int here = q.front();
    q.pop();

    if (here == k) {
      cnt++;
      continue;
    }

    for (int next : {here - 1, here + 1, here * 2}) {
      if ((next >= 0 && next <= 100000) &&
          (visited[next] == 0 || visited[next] == visited[here] + 1)) {
        visited[next] = visited[here] + 1;
        q.push(next);
      }
    }
  }

  cout << visited[k] - 1 << '\n' << cnt;

  return 0;
}

// 가중치가 같은 최단거리: BFS
// 네 방향이 아닌 세 방향 BFS
// 범위 체크
// 최단 거리이기 때문에 현재 노드에서 다음노드가 +1 한 것이 아니라면 방문하지
// 않는다. 먼저 방문하여 visited를 채운 값이 더 작은 값일 것이기 때문