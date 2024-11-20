#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), cmp);
    
    int left = 0, right = -1;
    
    for (auto a : targets){
        if(right <= a[0]){
            answer++;
            right = a[1];
        }
    }
    return answer;
}

// 1. 시작 지점 기반으로 정렬 오름차순 정렬
// 2. 반복문 돌면서
// 2-1. 이전 끝나는 시간보다 다음 시작하는 시간이 더 크다면 left rigth 갱신, ret++

// 그리디, 정렬
// 끝나는 지점 기반으로 오름차순 정렬
// right 값과 a[0]값을 비교하여 업데이트
