#include <bits/stdc++.h>

using namespace std;

stack<int> stk;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    
    for (int i=0; i<numbers.size(); i++){
        while(!stk.empty() && numbers[stk.top()] < numbers[i]){
            answer[stk.top()] = numbers[i];
            stk.pop();
        }
        stk.push(i);
    }
    
    return answer;
}