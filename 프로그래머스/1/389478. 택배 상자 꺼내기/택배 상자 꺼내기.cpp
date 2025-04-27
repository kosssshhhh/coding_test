#include <bits/stdc++.h>
using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    int target = 0;
    vector<stack<int>> v(w+1);
    
    for (int i=1; i<=n; i){
        
        if((i/w) % 2){
            // 정방향
            for (int j=0; j<w; j++){
                // cout << i << ' ';
                v[j].push(i);
                if(i == num) target = j;
                i++;
                if(i > n) break;
            }
        }else{
            // 역방향
            for(int j=w-1; j>=0; j--){
                // cout << i << ' ';
                v[j].push(i);
                if(i == num) target = j;
                i++;
                if(i > n) break;
            }
        }
    }
    
    while(!v[target].empty()){
        int temp = v[target].top();
        v[target].pop();
        
        answer++;    
        if(temp == num) break;
    }
    
    return answer;
}