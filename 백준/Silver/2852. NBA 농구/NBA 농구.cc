#include <bits/stdc++.h>
using namespace std;

int n, team, a, b, t_a, t_b, s_a, s_b, before_time;

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> team;
    scanf("%d:%d", &a, &b);

    int _time = a * 60 + b;

    // if (i == 0) {
    //   if (team == 1)
    //     s_a++;
    //   else if (team == 2)
    //     s_b++;
    //   before_time = _time;
    //   continue;
    // }

    if (s_a > s_b) {
      t_a += _time - before_time;
    } else if (s_a < s_b) {
      t_b += _time - before_time;
    } else {
      // nothing
    }

    if (team == 1)
      s_a++;
    else if (team == 2)
      s_b++;

    before_time = _time;
  }
  if (s_a > s_b) {
    t_a += 48 * 60 - before_time;
  } else if (s_a < s_b) {
    t_b += 48 * 60 - before_time;
  }

  printf("%02d:%02d\n", t_a / 60, t_a % 60);
  printf("%02d:%02d\n", t_b / 60, t_b % 60);

  return 0;
}