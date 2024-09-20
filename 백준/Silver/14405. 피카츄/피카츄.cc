#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    if (i < s.size() - 1 &&
        (s.substr(i, 2) == "pi" || s.substr(i, 2) == "ka")) {
      i += 1;
    } else if (i < s.size() - 2 && s.substr(i, 3) == "chu") {
      i += 2;
    } else {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}

// s.substr(0, 2) - 문자열 s의 0번째 인덱스부터 2개 뽑기