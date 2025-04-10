#include <bits/stdc++.h>

using namespace std;

int ret[1000004];
stack<int> stk;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    fill(ret, ret + 1000004, -1);
    
    for (int i=0; i<numbers.size(); i++){
        while(!stk.empty() && numbers[stk.top()] < numbers[i]){
            ret[stk.top()] = numbers[i];
            stk.pop();
        }
        stk.push(i);
    }
    
    for (int i=0; i<numbers.size(); i++){
        answer.push_back(ret[i]);
    }
    
    
    return answer;
}