#include <bits/stdc++.h>
using namespace std;

string input, r;
map<char, int> mp;
int odd_cnt = 0;
vector<char> ret;

int main() {
  cin >> input;

  // for (int i = 0; i < input.length(); i++) {
  //   mp[input[i]]++;
  // }
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

  // for (auto i : mp) cout << i.first << " : " << i.second << '\n';

  // Map 거꾸로 순회하여 오름차순, ret 배열의 앞 뒤로 삽입.
  // for (auto it = mp.rbegin(); it != mp.rend(); it++) {
  //   for (int i = 0; i < (*it).second; i++) {
  //     if ((*it).second == 0) break;

  //     // cout << (*it).first << " : " << (*it).second << '\n';
  //     ret.push_back((*it).first);
  //     ret.insert(ret.begin(), (*it).first);
  //     (*it).second -= 2;
  //   }
  // }

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