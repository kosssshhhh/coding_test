#include <bits/stdc++.h>
using namespace std;

string s;
int arr[26];
int n = 0;

int main() {
  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    n = s[i] - 'a';
    arr[n]++;
  }

  for (int i : arr) cout << i << ' ';

  return 0;
}