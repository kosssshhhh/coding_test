#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}
int solution(vector<vector<int>> targets) {
    int answer = 0;
    int n = targets.size();
    
    for (vector<int> a : targets){
        v.push_back({a[0], a[1]});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    int left = v[0].first, right = v[0].second;
    int ret = 1;
    
    for (int i=1; i<n; i++){
        if(right <= v[i].first){
            left = v[i].first;
            right = v[i].second;
            ret++;
        }
    }
    
    return ret;
}

// 1. 시작 지점 기반으로 정렬 오름차순 정렬
// 2. 반복문 돌면서
// 2-1. 이전 끝나는 시간보다 다음 시작하는 시간이 더 크다면 left rigth 갱신, ret++
