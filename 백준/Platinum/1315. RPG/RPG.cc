#include <bits/stdc++.h>
using namespace std;

struct quest {
  int x, y, c;
};

int n, dp[1001][1001];
bool visited[101];
vector<quest> a;

int rpg(int STR, int INT) {
  // 메모이제이션
  int &ret = dp[STR][INT];
  if (ret != -1) return ret;

  ret = 0;
  int pnt = 0;
  vector<int> v;

  for (int i = 0; i < n; i++) {
    if (a[i].x <= STR || a[i].y <= INT) {
      ret++;
      if (!visited[i]) {
        visited[i] = true;
        pnt += a[i].c;
        v.push_back(i);
      }
    }
  }

  for (int p = 0; p <= pnt; p++) {
    int nextSTR = min(1000, STR + p);
    int nextINT = min(1000, INT + pnt - p);
    ret = max(ret, rpg(nextSTR, nextINT));
  }

  for (int here : v) visited[here] = false;

  return ret;
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    int STR, INT, PNT;
    cin >> STR >> INT >> PNT;
    a.push_back({STR, INT, PNT});
  }

  memset(dp, -1, sizeof(dp));
  cout << rpg(1, 1);

  return 0;
}

// 힘, 지력 각각 1
// 총 N개의 퀘스트
// i번째 퀘스트를 꺠려면 STR[i] <= 힘 || INT[i] <= 지력
// 퀘스트 한번씩 꺨 수 있고, 순서 상관없음
// 스탯 마음대로

// 퀘스트 순서, 힘스탯, 지력스탯, 퀘스트 수행 개수
// 완탐, 50! x
// DP
