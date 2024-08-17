#include <bits/stdc++.h>
using namespace std;

string input, r;
map<char, int> mp;
int odd_cnt = 0;
vector<char> ret;

int main() {
  cin >> input;

  for (char c : input) {
    mp[c]++;
  }

  // 홀수 개수 판별 로직
  for (auto i : mp) {
    if (i.second % 2 == 1) {
      odd_cnt++;

      if (odd_cnt >= 2) {
        cout << "I'm Sorry Hansoo" << '\n';
        return 0;
      }

      ret.push_back(i.first);
      mp[i.first]--;
    }
  }

  // Map 거꾸로 순회하여 오름차순, ret 배열의 앞 뒤로 삽입.
  for (auto it = mp.rbegin(); it != mp.rend(); it++) {
    while ((*it).second > 1) {
      ret.push_back((*it).first);
      ret.insert(ret.begin(), (*it).first);
      (*it).second -= 2;
    }
  }

  for (auto it : ret) {
    cout << it;
  }
  cout << '\n';

  return 0;
}

// Map을 활용하여 풀이
// cnt 배열을 활용해서 풀 수도 있음
