const dfs = (here, adj, visited) => {
    visited.add(here)
    
    adj[here].forEach(there => {
        if(!visited.has(there)){
            dfs(there, adj, visited);
        }
    })
}

function solution(n, computers) {
    let ret = 0;
    
    const adj = Array.from({length: n}, () => []);
    const visited = new Set();
    
    for (let i=0; i<computers.length; i++){
        for (let j=0; j<computers[0].length; j++){
            if(i !== j && computers[i][j]){
                adj[i].push(j);
                adj[j].push(i);
            }
        }
    }
    
    for (let i=0; i<n; i++){
        if(!visited.has(i)){
            ret ++;
            dfs(i, adj, visited);
        }
    }
    
    return ret;
}