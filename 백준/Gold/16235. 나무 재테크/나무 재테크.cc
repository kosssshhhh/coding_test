#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> a[14][14];          // 나무
int A[14][14], ground[14][14];  // 기계가 뿌릴 양분, 현재 땅의 양분
int n, m, k, x, y, c, ret;

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cin >> A[i][j];
  }

  fill(&ground[0][0], &ground[0][0] + 14 * 14, 5);

  for (int i = 0; i < m; i++) {
    cin >> x >> y >> c;
    x--, y--;
    a[x][y].push_back(c);
  }

  while (k--) {
    // 봄
    // 여름
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j].size() == 0) continue;
        int die_tree = 0;
        vector<int> temp;
        sort(a[i][j].begin(), a[i][j].end());
        for (int tree : a[i][j]) {
          if (ground[i][j] >= tree) {
            ground[i][j] -= tree;
            temp.push_back(tree + 1);
          } else {
            die_tree += tree / 2;
          }
        }
        a[i][j] = temp;
        ground[i][j] += die_tree;
      }
    }

    // 가을
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j].size() == 0) continue;
        for (int tree : a[i][j]) {
          if (tree % 5 == 0) {
            // 번식
            for (int l = 0; l < 8; l++) {
              int ny = i + dy[l];
              int nx = j + dx[l];
              if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
              a[ny][nx].push_back(1);
            }
          }
        }
      }
    }
    // 겨울
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ground[i][j] += A[i][j];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ret += a[i][j].size();
    }
  }

  cout << ret;

  return 0;
}

// 초기 N x N 짜리 양분 5짜리 땅 만들기
// 입력받은 해마다 양분 배열 저장
// x,y,나이 받기 (구조체, 벡터)
// k 만큼 반복문 돌리고
// 그 안에 봄 여름 가을 겨울 로직 추가
