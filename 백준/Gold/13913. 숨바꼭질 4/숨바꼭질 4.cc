#include <bits/stdc++.h>
using namespace std;

#define prev aaa

int n, k, prev[100004], visited[100004];
queue<int> q;
vector<int> v;

int main() {
  cin >> n >> k;

  visited[n] = 1;
  q.push(n);

  while (q.size()) {
    int here = q.front();
    q.pop();

    if (here == k) {
      break;
    }

    for (int next : {here + 1, here - 1, here * 2}) {
      if (next < 0 || next > 100000) continue;
      if (visited[next] == 0 || visited[next] == visited[here] + 1) {
        q.push(next);
        visited[next] = visited[here] + 1;
        prev[next] = here;
      }
    }
  }
  for (int i = k; i != n; i = prev[i]) v.push_back(i);

  v.push_back(n);

  cout << visited[k] - 1 << '\n';
  reverse(v.begin(), v.end());
  for (int i : v) cout << i << ' ';
  return 0;
}

// 최단거리: BFS
// 네방향이 아닌 세방향 BFS
// 이전 위치 추적할 떄(trace) prev, next 쓰면 된다.