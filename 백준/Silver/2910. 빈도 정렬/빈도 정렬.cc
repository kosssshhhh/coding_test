#include <bits/stdc++.h>
using namespace std;

int N, C;
vector<int> v;
map<int, int> mp1, mp2;

bool cmp(int a, int b) {
  if (mp1[a] == mp1[b]) return mp2[a] < mp2[b];
  return mp1[a] > mp1[b];
}

int main() {
  cin >> N >> C;

  for (int i = 0; i < N; i++) {
    int p;
    cin >> p;
    v.push_back(p);

    mp1[p]++;
    if (!mp2[p]) mp2[p] = i + 1;
  }

  sort(v.begin(), v.end(), cmp);

  for (int a : v) {
    cout << a << ' ';
  }

  return 0;
}