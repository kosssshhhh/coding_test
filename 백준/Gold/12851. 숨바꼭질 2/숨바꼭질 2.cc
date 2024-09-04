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
    int a = q.front();
    // cout << a << '\n';
    q.pop();
    if (a == k) {
      v.push_back(visited[a]);
      cnt++;
      continue;
    }

    for (int next : {a - 1, a + 1, a * 2}) {
      if ((next >= 0 && next <= 100000) &&
          (visited[next] == 0 || visited[next] == visited[a] + 1)) {
        visited[next] = visited[a] + 1;
        q.push(next);
      }
    }
  }

  cout << visited[k] - 1 << '\n' << cnt;

  return 0;
}