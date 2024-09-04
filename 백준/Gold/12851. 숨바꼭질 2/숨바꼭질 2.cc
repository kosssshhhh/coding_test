#include <bits/stdc++.h>
using namespace std;

int n, k, cnt, visited[100004];
queue<int> q;
vector<int> v;

int main() {
  cin >> n >> k;

  q.push(n);
  visited[n] = 1;

  while (q.size()) {
    int here = q.front();
    // cout << here << '\n';
    q.pop();
    if (here == k) {
      v.push_back(visited[here]);
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