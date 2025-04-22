#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int ret = 0;
    int n = board[0].size();
    
    vector<stack<int>> stks(n);
    stack<int> stk;
    
    for (int i=n-1; i>=0; i--){
        for(int j=0; j<n; j++){
            if(board[i][j] != 0){
                stks[j].push(board[i][j]);    
            }
        }
    }
    
    for (int m : moves){
        if(stks[m-1].empty()) continue;
        
        int here = stks[m-1].top();
        cout << here << '\n';
        stks[m-1].pop();
        
        if(!stk.empty() && stk.top() == here){
            stk.pop();
            ret += 2;
        }else{
            stk.push(here);
        }
    }
    
    return ret;
}