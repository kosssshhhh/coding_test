

function solution(n, computers) {
    let ret = 0;
    const visited = new Set();
    
    const dfs = (here) => {
        visited.add(here);
        
        for (let i=0; i<n; i++){
            if(computers[here][i] === 1 && !visited.has(i)){
                dfs(i);
            }
        }
    }
    
    for(let i=0; i<n; i++){
        if(!visited.has(i)){
            ret++;
            dfs(i);
        }
    }
    
    return ret;
}