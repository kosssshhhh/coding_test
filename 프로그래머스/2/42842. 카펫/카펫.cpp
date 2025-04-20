#include <string>
#include <vector>

using namespace std;

#include <bits/stdc++.h>

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> v;
    
    int sum = brown + yellow;
    
    
    for (int i=1; i<=sum; i++){
        if(sum % i == 0){
            v.push_back(i);
        }
    }
    
    if(v.size() % 2 == 1){
        answer.push_back(v[v.size() / 2]);
        answer.push_back(v[v.size() / 2]);
    }else {
        answer.push_back(v[v.size() / 2]);
        answer.push_back(v[v.size() / 2 - 1]);
    }
    
    
    
    return answer;
}