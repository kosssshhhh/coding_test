#include <bits/stdc++.h>
using namespace std;

string s;
int a[27];

int main() {
  cin >> s;

  for (char c : s) a[c - 'a']++;

  for (int i = 0; i < 26; i++) cout << a[i] << ' ';

  return 0;
}