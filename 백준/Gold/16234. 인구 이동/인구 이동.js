const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const [N, L, R] = input[0].split(' ').map(Number);
const a = input.slice(1).map(line => line.split(' ').map(Number));

const dir = [[-1, 0], [0, 1], [1, 0], [0, -1]];
let v = [], ret = 0;
let visited = Array.from({length: 54}, () => Array(54).fill(0));

function dfs(y, x) {
    visited[y][x] = 1;
    v.push([y, x]);
    let ret = a[y][x];

    for (let d of dir){
        const [ny, nx] = [y + d[0], x + d[1]];

        if(ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) continue;
        let dist = Math.abs(a[ny][nx] - a[y][x]);
        
        if(L <= dist && dist <= R){
            ret += dfs(ny, nx);
        }
    }
    return ret;
}

function answer(){
    while(true){
        visited = Array.from({length: 54}, () => Array(54).fill(0));
        let flag = false;

        for (let i = 0; i < N; i++){
            for (let j = 0; j < N; j++){
                if(visited[i][j]) continue;
                v = [];

                let sum = dfs(i, j);

                if(v.length !== 1){
                    flag = true;
                    for(let it of v){
                        a[it[0]][it[1]] = Math.floor(sum / v.length);
                    }
                }

            }
        }
        if(flag) ret++;
        else break;
    }
    console.log(ret);
    
}

answer();