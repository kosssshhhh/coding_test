#include <bits/stdc++.h>

using namespace std;

int solution(string dirs) {
    int ret = 0;
    int y=5, x=5; // 시작 위치, 평면이동을 통해 0~10 범위로 이동
    int visited[12][12][12][12]; // 현재 위치, 다음 위치를 통해 경로 방문 처리
    map<char, pair<int,int>> mp;
    
    // 방향 벡터 Map 
    mp['U'] = {1, 0};
    mp['R'] = {0, 1};
    mp['D'] = {-1, 0};
    mp['L'] = {0, -1};
    
    for (char dir : dirs){
        int dy, dx;
        tie(dy, dx) = mp[dir];
        
        int ny = y + dy;
        int nx = x + dx;
        
        // 좌표평면 이탈
        if(ny > 10 || nx > 10 || ny < 0 || nx < 0) continue;
        
        if(!visited[y][x][ny][nx]){
            visited[y][x][ny][nx] = 1;
            visited[ny][nx][y][x] = 1; // 양방향 다 체크해줘야함
            ret++;
        }
        y = ny; 
        x = nx;
    }
    
    return ret;
}