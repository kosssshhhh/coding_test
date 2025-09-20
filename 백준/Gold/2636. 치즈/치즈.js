const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const [N, M] = input[0].split(' ').map(Number);
const arr = input.slice(1).map(line => line.split(' ').map(Number));

const dir = [[-1, 0], [0, 1], [1, 0], [0, -1]];
let visited = Array.from({length: 104}, () => Array(104).fill(0));
let v = [];


let cnt = 0, t = 0;
arr.forEach(line => line.forEach(c => c === 1 && cnt++));

const dfs = (y, x) => {
    visited[y][x] = 1;
    
    for (const [dy, dx] of dir){
        const ny = y + dy;
        const nx = x + dx;
        
        if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;
        if(arr[ny][nx] === 1) {
            v.push([ny, nx]);
            visited[ny][nx] = 1;
        }else if(arr[ny][nx] == 0){
            dfs(ny, nx);
        }
    }
}


const answer = () => {
    while(cnt > v.length){
        t++;

        for (let i = 0; i < N; i++){
            dfs(i, 0);
            dfs(i, M);
        }
    
        for (let i = 0; i < M; i++){
            dfs(0, i);
            dfs(N, i);
        }

        if(cnt - v.length <= 0) break;
        cnt -= v.length;
        
        for (let i = 0; i < v.length; i++){
            arr[v[i][0]][v[i][1]] = 0; // 업데이트
        }

        visited = Array.from({length: 104}, () => Array(104).fill(0));
        v = []
        
    }

    console.log(t);
    console.log(cnt);
    
}

answer();