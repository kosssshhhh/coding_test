#include <bits/stdc++.h>
using namespace std;

int n, ret;
string arr[104], k;
vector<string> v;
stack<char> st;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> k;
    v.push_back(k);
  }

  for (string s : v) {
    while (!st.empty()) st.pop();

    for (char c : s) {
      if (st.empty()) {
        st.push(c);
      } else {
        char temp = st.top();

        if (temp != c) {
          st.push(c);
        } else {
          st.pop();
        }
      }
    }

    if (st.size() == 0) ret++;
  }

  cout << ret << "\n";

  return 0;
}