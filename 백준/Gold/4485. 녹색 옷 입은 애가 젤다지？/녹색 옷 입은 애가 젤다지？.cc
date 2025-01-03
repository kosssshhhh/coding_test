#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, t, a[130][130], dist[130][130];

void dijkstra() {
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                 greater<pair<int, pair<int, int>>>>
      pq;

  dist[0][0] = a[0][0];
  pq.push({a[0][0], {0, 0}});

  while (pq.size()) {
    int here_cost = pq.top().first;

    int y, x;
    tie(y, x) = pq.top().second;

    pq.pop();

    // printf("%d : %d\n", y, x);

    if (here_cost != dist[y][x]) continue;

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

      int new_cost = here_cost + a[ny][nx];

      if (dist[ny][nx] > new_cost) {
        dist[ny][nx] = new_cost;
        pq.push({new_cost, {ny, nx}});
      }
    }
  }
}

int main() {
  while (true) {
    cin >> n;
    if (n == 0) break;
    t++;
    fill(&dist[0][0], &dist[0][0] + 130 * 130, INF);
    fill(&a[0][0], &a[0][0] + 130 * 130, -1);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }

    dijkstra();
    cout << "Problem " << t << ": " << dist[n - 1][n - 1] << '\n';
  }

  return 0;
}