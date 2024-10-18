#include <bits/stdc++.h>
using namespace std;

vector<int> adj[204];
int visited[204];

void dfs(int here){
    visited[here] = 1;
    
    for(int there : adj[here]){
        if(visited[there]) continue;
        dfs(there);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int ret = 0;
    
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if(i != j && computers[i][j]){
                adj[i].push_back(j);
            }
        }
    }
    
    for (int i=0; i<n; i++){
        if(!visited[i]){
            ret++;
            dfs(i);
        }
    }
    
    return ret;
}