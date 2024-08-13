#include <bits/stdc++.h>
using namespace std;

int N, sum;
string arr[154];
string ret;

int main() {
  cin >> N;
  vector<char> uniq_v;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    uniq_v.push_back(arr[i][0]);
  }

  sort(uniq_v.begin(), uniq_v.end());
  uniq_v.erase(unique(uniq_v.begin(), uniq_v.end()), uniq_v.end());

  for (char i : uniq_v) {
    sum = 0;
    for (string s : arr) {
      if (s[0] == i) {
        sum++;
      }
    }
    if (sum >= 5) ret += i;
  }

  if (ret == "") ret = "PREDAJA";

  for (int i = 0; i < ret.length(); i++) cout << ret[i];
  return 0;
}