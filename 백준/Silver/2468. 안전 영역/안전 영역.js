const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

const n = Number(input[0]);

const map = input.slice(1).map(line => line.split(' ').map(Number));

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

const dfs = (y, x, h, visited) => {
    visited[y][x] = 1;

    for (let i=0; i<4; i++){
        const ny = y + dy[i];
        const nx = x + dx[i];

        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(map[ny][nx] <= h || visited[ny][nx]) continue;

        dfs(ny, nx, h, visited);
    }
}


const answer = (n, map) => {
    let ret = 0;

    for(let h=0; h<=100; h++){
        const visited = Array.from({length: n}, ()=>Array(n).fill(0));
        let cnt = 0;

        for (let i=0; i<n; i++){
            for (let j=0; j<n; j++){
                if(map[i][j] <= h || visited[i][j]) continue;
                dfs(i, j, h, visited);
                cnt++; 
            }
        }
        ret = Math.max(ret, cnt);
    }

    return ret;
}

console.log(answer(n, map));