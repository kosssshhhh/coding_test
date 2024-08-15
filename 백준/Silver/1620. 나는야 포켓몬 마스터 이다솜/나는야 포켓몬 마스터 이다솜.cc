#include <bits/stdc++.h>
using namespace std;

int N, M;
string temp, poke[100004];
map<string, int> mp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    poke[i + 1] = temp;
    mp[temp] = i + 1;
  }

  for (int i = 0; i < M; i++) {
    cin >> temp;
    if (atoi(temp.c_str()) == 0) {
      cout << mp[temp] << '\n';
    } else {
      cout << poke[atoi(temp.c_str())] << '\n';
    }
  }
  return 0;
}
