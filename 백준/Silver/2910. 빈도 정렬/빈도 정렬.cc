#include <bits/stdc++.h>
using namespace std;

int n, c;
int a;
map<int, int> mp;
map<int, int> mp_first;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.second == b.second) return mp_first[a.first] < mp_first[b.first];
  return a.second > b.second;
}

int main() {
  cin >> n >> c;
  for (int i = 0; i < n; i++) {
    cin >> a;
    mp[a]++;
    if (mp_first[a] == 0) mp_first[a] = i + 1;
  }

  vector<pair<int, int>> v(mp.begin(), mp.end());

  sort(v.begin(), v.end(), cmp);

  for (auto n : v) {
    for (int i = 0; i < n.second; i++) cout << n.first << ' ';
  }
  cout << '\n';

  return 0;
}