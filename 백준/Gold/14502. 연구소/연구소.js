const input = require("fs").readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt").toString().trim().split('\n');

const [N, M] = input[0].split(' ').map(Number);
const a = input.slice(1).map(line => line.split(' ').map(Number));

const dir = [[-1, 0], [0, 1], [1, 0], [0, -1]];
const arr = [];
let visited = Array.from({length: N}, () => Array(M).fill(0));
let cnt = 0, wall_cnt = 0, ret = Infinity;

const dfs = (y, x) => {
    visited[y][x] = 1; 
    cnt++;

    for (let i = 0; i < 4; i++){
        const [ny, nx] = [y + dir[i][0], x + dir[i][1]];

        if(ny < 0 || nx < 0 || ny >= N || nx >= M ) continue;
        if(a[ny][nx] === 0 && visited[ny][nx] === 0){
            dfs(ny, nx);
        }
    }

}

const answer = (N, M, a) => {
    a.forEach(i => {
        if(i === 1) wall_cnt++;
        else if(i === 0) {
            arr.push()
        }
    })

    for (let i = 0; i < N; i++){
        for (let j = 0; j < M; j++){
            if(a[i][j] === 1) wall_cnt++;
            else if(a[i][j] === 0){
                arr.push([i, j]);
            }
        }
    }

    for(let i = 0; i < arr.length; i++){
        for (let j = i + 1; j < arr.length; j++){
            for (let k = j + 1; k < arr.length; k++){
                a[arr[i][0]][arr[i][1]] = 1;
                a[arr[j][0]][arr[j][1]] = 1;
                a[arr[k][0]][arr[k][1]] = 1;

                for (let l = 0; l < N; l++){
                    for (let m = 0; m < M; m++){
                        if(a[l][m] == 2 && visited[l][m] == 0){
                            dfs(l, m);
                        }
                    }
                }

                ret = Math.min(ret, cnt);
                cnt = 0;
                visited = Array.from({length: N}, () => Array(M).fill(0));

                a[arr[i][0]][arr[i][1]] = 0;
                a[arr[j][0]][arr[j][1]] = 0;
                a[arr[k][0]][arr[k][1]] = 0;
            }
        }
    }

    return M * N - wall_cnt - 3 - ret;
}

console.log(answer(N, M, a));


