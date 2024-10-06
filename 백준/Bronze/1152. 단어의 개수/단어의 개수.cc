#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> v;

vector<string> split(const string& input, string delimeter) {
  vector<string> result;
  auto start = 0;
  auto end = input.find(delimeter);
  while (end != string::npos) {
    result.push_back(input.substr(start, end - start));
    start = end + delimeter.size();
    end = input.find(delimeter, start);
  }
  result.push_back(input.substr(start));
  return result;
}

int main() {
  getline(cin, s);
  if (s == " ") {
    cout << 0 << '\n';
    return 0;
  }
  if (s[0] == ' ') s[0] = 'i';

  vector<string> ret = split(s, " ");

  if (ret[ret.size() - 1] == "")
    cout << ret.size() - 1;
  else
    cout << ret.size();
  return 0;
}