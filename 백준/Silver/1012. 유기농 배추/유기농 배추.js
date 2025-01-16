const fs = require('fs');
// const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const t = Number(input[0])
let line = 1;

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

const dfs = (y, x, visited, n, m, a) =>{
    visited[y][x] = 1;
    
    for(let i=0; i<4; i++){
        const ny = y + dy[i];
        const nx = x + dx[i];

        if(ny <0 || nx < 0|| ny >= n || nx >= m || visited[ny][nx] || !a[ny][nx]) continue;
        dfs(ny, nx, visited, n, m, a);
    }
}

for (let i=0; i<t; i++){
    const [n, m, k] = input[line++].split(' ').map(Number);

    let ret = 0;
    const a = Array.from({length: n}, () => Array(m).fill(0));
    const visited = Array.from({length: n}, () => Array(m).fill(0));

    for (let j=0; j<k; j++){
        const [y, x] = input[line++].split(' ').map(Number);
        a[y][x] = 1;
    }

    // 로직
    for(let i=0; i<n; i++){
        for(let j=0; j<m; j++){
            if(visited[i][j] || a[i][j] === 0) continue;
            dfs(i, j, visited, n, m, a);
            ret++;
        }
    }

    console.log(ret);
}