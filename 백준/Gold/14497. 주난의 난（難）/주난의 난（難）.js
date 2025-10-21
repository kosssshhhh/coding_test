const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const [N, M] = input[0].split(' ').map(Number);
const [x1, y1, x2, y2] = input[1].split(' ').map(Number);
const a = input.slice(2).map(line => line.split(''));

const dir = [[0, 1], [1, 0], [0, -1], [-1, 0]];
let v = [], visited = Array.from({length: 304}, () => Array(304).fill(0));
let ret = 0, flag = 0;

function dfs(x, y) {
    visited[x][y] = 1;

    for(const [dx, dy] of dir){
        const [nx, ny] = [x + dx, y + dy];

        if(nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny]) continue;
        if(a[nx][ny] === '1'){
            v.push([nx, ny]);
        }else if(a[nx][ny] === '0'){
            dfs(nx, ny);
        }else if(a[nx][ny] === '*'){
            flag++;
            return;
        }
    }
    return ;

}

function answer(){
    while(true){
        ret++;

        dfs(x2 - 1, y2 - 1);

        if(flag){
            break;
        }

        for (const [x, y] of v){
            a[x][y] = '0';
        }

        v = [];
        visited = Array.from({length: 304}, () => Array(304).fill(0));
    }

    console.log(ret);

}

answer();