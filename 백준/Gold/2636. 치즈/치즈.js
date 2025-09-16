const input = require('fs').readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt").toString().trim().split('\n');

const [N, M] = input[0].split(' ').map(Number);
const a = input.slice(1).map(line => line.split(' ').map(Number));

const dir = [[-1, 0], [0, 1], [1, 0], [0, -1]];
let cnt = 0, ret = 0;
let visited = Array.from({length: N}, () => Array(M).fill(0));
let v = [];

const dfs = (y, x) => {
    visited[y][x] = 1;

    for (let i = 0; i < 4; i++){
        const [ny, nx] = [y + dir[i][0], x + dir[i][1]];
        
        if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;
        if(a[ny][nx] == 1){
            v.push([ny, nx]);
            visited[ny][nx] = 1;
        }else{
            dfs(ny, nx);
        }
    }
}

const answer = () => {
    a.forEach(line => line.forEach(i => i === 1 && cnt++))
    
    while(cnt > 0){
        ret++;

        for(let i = 0; i < N; i++){
            dfs(i, 0);
            dfs(i, M - 1);
        }

        for (let i = 0; i < M; i++){
            dfs(0, i);
            dfs(N - 1, i);
        }

        if(cnt - v.length <= 0) break;
        cnt -= v.length;

        v.forEach(([y, x]) => a[y][x] = 0);

        visited = Array.from({length: N}, () => Array(M).fill(0));
        v = [];
    }

    console.log(ret);
    console.log(cnt);
}

answer();