#include <bits/stdc++.h>

using namespace std;

int go(int idx, int v, int target, vector<int> &numbers){
    // 기저사례
    if(idx == numbers.size()){
        if(v == target) return 1;
        else return 0;
    }
    
    // 로직
    return go(idx + 1, v + numbers[idx], target, numbers) + go(idx + 1, v - numbers[idx], target, numbers);
}

int solution(vector<int> numbers, int target) {    
    return go(0, 0, target, numbers);
}