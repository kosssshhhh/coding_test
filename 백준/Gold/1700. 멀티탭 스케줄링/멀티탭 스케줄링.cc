#include <bits/stdc++.h>
using namespace std;
#define INF 987654321;

int n, k, a[104], visited[104], ret;
vector<int> v;

int main() {
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < k; i++) {
    if (!visited[a[i]]) {
      if (v.size() == n) {
        int last_idx = 0;
        int pos;
        for (int _a : v) {
          int here = INF;
          for (int j = i + 1; j < k; j++) {
            if (_a == a[j]) {
              here = j;
              break;
            }
          }
          if (last_idx < here) {
            last_idx = here;
            pos = _a;
          }
        }
        visited[pos] = 0;
        ret++;
        v.erase(find(v.begin(), v.end(), pos));
      }
      v.push_back(a[i]);
      visited[a[i]] = 1;
    }
  }

  cout << ret;
  return 0;
}