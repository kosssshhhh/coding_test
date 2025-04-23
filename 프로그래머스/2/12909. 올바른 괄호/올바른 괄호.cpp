#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    bool answer = true;

   stack<char> stk;
    
    for (char c : s){
        if(!stk.empty() && stk.top() == '(' && c == ')') stk.pop();
        else stk.push(c);
    }
    
    answer = stk.empty() ? true : false;

    return answer;
}