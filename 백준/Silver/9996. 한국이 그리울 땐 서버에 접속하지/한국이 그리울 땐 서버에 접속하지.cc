#include <bits/stdc++.h>
using namespace std;

int N;
string pattern, temp, str1, str2;
vector<string> v, s;

vector<string> split(string input, string delimeter) {
  long long pos = 0;
  string token = "";
  vector<string> ret;

  while ((pos = input.find(delimeter)) != string::npos) {
    token = input.substr(0, pos);
    ret.push_back(token);
    input.erase(0, pos + delimeter.length());
  }
  ret.push_back(input);

  return ret;
}

int main() {
  cin >> N >> pattern;

  for (int i = 0; i < N; i++) {
    cin >> temp;
    v.push_back(temp);
  }

  s = split(pattern, "*");

  for (string i : v) {
    str1 = "";
    str2 = "";
    if (s[0].length() > i.length() || s[1].length() > i.length()) {
      cout << "NE" << '\n';
      continue;
    }
    if (i.length() < s[0].length() + s[1].length()) {
      cout << "NE" << '\n';
      continue;
    }

    str1 = i.substr(0, s[0].length());
    str2 = i.substr(i.length() - s[1].length(), s[1].length());

    if (str1 == s[0] && str2 == s[1])
      cout << "DA" << '\n';
    else
      cout << "NE" << '\n';
  }

  return 0;
}