#include <bits/stdc++.h>
using namespace std;

int N, C, a;
vector<int> v;
map<int, int> cnt, idx;

bool comp(int a, int b) {
  if (cnt[a] == cnt[b]) {
    return idx[a] < idx[b];
  }
  return cnt[a] > cnt[b];
}

int main() {
  cin >> N >> C;

  for (int i = 0; i < N; i++) {
    cin >> a;
    v.push_back(a);

    cnt[a]++;
    if (!idx[a]) {
      idx[a] = i + 1;
    }
  }
  sort(v.begin(), v.end(), comp);

  for (int a : v) {
    cout << a << ' ';
  }

  return 0;
}