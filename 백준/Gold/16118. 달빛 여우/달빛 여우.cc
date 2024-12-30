#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PI;
typedef tuple<int, int, bool> TI;

int n, m, a, b, d, ret, here, cnt, dist[4001], dist_wolf[4001][2];
vector<PI> adj[4001];
const int INF = 987654321;

// 달빛 여우 dist 배열 구하기
void dijkstra() {
  fill(dist, dist + 4001, INF);
  priority_queue<PI, vector<PI>, greater<PI>> pq;
  dist[1] = 0;
  pq.push({0, 1});

  while (pq.size()) {
    int here = pq.top().second;
    int here_dist = pq.top().first;
    pq.pop();

    if (dist[here] != here_dist) continue;

    for (PI there : adj[here]) {
      int next = there.second;
      int d = there.first;
      if (dist[next] > dist[here] + d) {
        dist[next] = dist[here] + d;
        pq.push({dist[next], next});
      }
    }
  }
}

void dijkstra2() {
  fill(&dist_wolf[0][0], &dist_wolf[0][0] + 4001 * 2, INF);
  priority_queue<TI, vector<TI>, greater<TI>> pq;
  dist_wolf[1][0] = 0;
  pq.push({0, 1, 0});

  while (pq.size()) {
    int d, here, cnt;
    tie(d, here, cnt) = pq.top();
    pq.pop();

    if (dist_wolf[here][cnt] != d) continue;

    for (PI there : adj[here]) {
      int next = there.second;
      int d = !cnt ? there.first / 2 : there.first * 2;

      if (dist_wolf[next][!cnt] > dist_wolf[here][cnt] + d) {
        dist_wolf[next][!cnt] = dist_wolf[here][cnt] + d;
        pq.push({dist_wolf[next][!cnt], next, !cnt});
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> d;
    adj[a].push_back({d * 2, b});
    adj[b].push_back({d * 2, a});
  }

  dijkstra();
  dijkstra2();

  for (int i = 2; i <= n; i++) {
    int d = min(dist_wolf[i][0], dist_wolf[i][1]);
    if (d > dist[i]) ret++;
  }

  cout << ret;

  return 0;
}