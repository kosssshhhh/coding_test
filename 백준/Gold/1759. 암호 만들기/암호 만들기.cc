#include <bits/stdc++.h>
using namespace std;

int L, C;
vector<char> v;

void go(int idx, vector<int> vv) {
  if (idx >= C) return;
  if (vv.size() == L) {
    int cntJa = 0;
    bool isMo = false;
    for (int i : vv) {
      char c = v[i];
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        isMo = true;
      else
        cntJa++;
    }
    if (cntJa >= 2 && isMo) {
      for (int i : vv) cout << v[i];
      cout << '\n';
    }
    return;
  }

  vv.push_back(idx + 1);
  go(idx + 1, vv);
  vv.pop_back();

  go(idx + 1, vv);

  return;
}

int main() {
  cin >> L >> C;
  for (int i = 0; i < C; i++) {
    char temp;
    cin >> temp;
    v.push_back(temp);
  }

  sort(v.begin(), v.end());

  vector<int> vv;
  go(-1, vv);

  return 0;
}