#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, m, T, D, a[30][30], b[3000][3000], ret;
char temp[30][30];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<int> v;
string s;

int main() {
  cin >> n >> m >> T >> D;
  // 입출력 전처리
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] >= 'a')
        a[i][j] = s[j] - 'a' + 26;
      else
        a[i][j] = s[j] - 'A';
    }
  }

  ret = a[0][0];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      v.push_back(i * 100 + j);
    }
  }

  // 최단거리를 구하므로 INF로 초기화
  fill(&b[0][0], &b[0][0] + 3000 * 3000, INF);

  // 정점간 가중치 배열 생성
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int d = 0; d < 4; d++) {
        int ny = i + dy[d];
        int nx = j + dx[d];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

        int diff = abs(a[i][j] - a[ny][nx]);

        if (diff <= T) {
          if (a[ny][nx] > a[i][j]) {
            b[i * 100 + j][ny * 100 + nx] = diff * diff;
          } else
            b[i * 100 + j][ny * 100 + nx] = 1;
        }
      }
    }
  }

  // 플로이드 워셜 최단거리
  for (int k : v) {
    for (int i : v) {
      for (int j : v) {
        b[i][j] = min(b[i][j], b[i][k] + b[k][j]);  // i,j 사이 k를 경유했을 때
      }
    }
  }

  for (int j : v) {
    // 호텔에서 출발하어 호텔로 돌아와야함
    if (D >= b[0][j] + b[j][0]) {
      ret = max(ret, a[j / 100][j % 100]);
    }
  }
  cout << ret << '\n';

  return 0;
}