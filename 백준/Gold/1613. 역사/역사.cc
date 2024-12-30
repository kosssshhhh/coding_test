#include <bits/stdc++.h>
using namespace std;

int n, k, s, e, t, dist[401][401];
const int INF = 987654321;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j)
        dist[i][j] = 0;
      else
        dist[i][j] = INF;
    }
  }

  for (int i = 0; i < k; i++) {
    cin >> s >> e;
    dist[s][e] = -1;
    dist[e][s] = 1;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (dist[i][k] == 1 && dist[k][j] == 1) {
          dist[i][j] = 1;
        } else if (dist[i][k] == -1 && dist[k][j] == -1) {
          dist[i][j] = -1;
        }
      }
    }
  }

  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> s >> e;
    if (dist[s][e] == INF)
      cout << 0 << '\n';
    else if (dist[s][e] == -1)
      cout << -1 << '\n';
    else if (dist[s][e] == 1)
      cout << 1 << '\n';
  }

  return 0;
}