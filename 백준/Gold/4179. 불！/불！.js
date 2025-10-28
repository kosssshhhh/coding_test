const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const [R, C] = input[0].split(' ').map(Number);
const a = input.slice(1).map(line => line.split(''));

const dir = [[-1, 0], [0, 1], [1, 0], [0, -1]];
const f_visited = Array.from({length: R}, () => Array(C).fill(Infinity));
const j_visited = Array.from({length: R}, () => Array(C).fill(0));
let ji;

const queue = [];

for (let i = 0; i < R; i++){
    for (let j = 0; j < C; j++){
        if(a[i][j] === 'F'){
            f_visited[i][j] = 1;
            queue.push([i, j]);
        }else if(a[i][j] === 'J'){
            ji = [i, j];
        }
    }
}

function answer(){
    while(queue.length){
        const [y, x] = queue.shift();
        
        for (const d of dir){
            const [ny, nx] = [y + d[0], x + d[1]];

            if(ny < 0 || nx < 0 || ny >= R || nx >= C || f_visited[ny][nx] !== Infinity || a[ny][nx] === '#') continue;
            f_visited[ny][nx] = f_visited[y][x] + 1;
            queue.push([ny, nx]);
        }
    }
    
    queue.push(ji);
    j_visited[ji[0]][ji[1]] = 1;

    while(queue.length){
        const [y, x] = queue.shift();

        if(y === 0 || x === 0 || y === R - 1 || x === C - 1){
            console.log(j_visited[y][x]);
            return;
        }

        for (const d of dir){
            const [ny, nx] = [y + d[0], x + d[1]];
            
            if(ny < 0 || nx < 0 || ny >= R || nx >= C || j_visited[ny][nx] || a[ny][nx] === '#') continue;
            if(j_visited[y][x] + 1 < f_visited[ny][nx]){
                j_visited[ny][nx] = j_visited[y][x] + 1;
                queue.push([ny, nx]);
            }
        }
    }

    console.log("IMPOSSIBLE");
}

answer();