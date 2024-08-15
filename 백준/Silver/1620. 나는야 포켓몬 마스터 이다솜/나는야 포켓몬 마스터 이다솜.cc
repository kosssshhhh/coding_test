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

// string -> int
// int -> string 구조일 떄 
// 하나의 자료구조로 처리하면 시간이 너무 오래걸림
// 따라서 각각 빠른 자료구조를 선택하여 사용할 수 있다.
// string -> int : Map 사용
// int -> string : Array 혹은 Map 사용