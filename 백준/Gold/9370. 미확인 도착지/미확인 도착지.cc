#include <bits/stdc++.h>
using namespace std;

const int INF = 987654322;
int T, n, m, t, s, g, h, dist[2004], a, b, c, d;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;

  while (T--) {
    vector<pair<int, int>> adj[2004];
    cin >> n >> m >> t >> s >> g >> h;
    for (int i = 0; i < m; i++) {
      cin >> a >> b >> d;
      d *= 2;

      if (a == g && b == h) {
        d--;
      } else if (a == h && b == g)
        d--;

      adj[a].push_back(make_pair(d, b));
      adj[b].push_back(make_pair(d, a));
    }

    int candi[t + 1];
    for (int i = 0; i < t; i++) {
      cin >> candi[i];
    }
    sort(candi, candi + t);
    fill(dist, dist + 2004, INF);

    // 다익스트라
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    pq.push({0, s});
    dist[s] = 0;

    while (pq.size()) {
      int here_dist = pq.top().first;
      int here = pq.top().second;
      pq.pop();

      if (here_dist != dist[here]) continue;

      for (pair<int, int> there : adj[here]) {
        int _dist = there.first;
        int _there = there.second;

        if (dist[_there] > dist[here] + _dist) {
          dist[_there] = dist[here] + _dist;
          pq.push({dist[_there], _there});
        }
      }
    }

    for (int i = 0; i < t; i++) {
      if (dist[candi[i]] % 2 == 1) cout << candi[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}