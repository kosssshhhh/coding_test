const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const N = Number(input[0]);
const scv = input[1].split(' ').map(Number);
while(scv.length !== 3) scv.push(0);

const attack = [[9, 3, 1], [9, 1, 3], [3, 9, 1], [3, 1, 9], [1, 9, 3], [1, 3, 9]];
const visited = Array.from({length: 64}, () => Array.from({length: 64}, () => Array(64).fill(0)));

function answer(){
    const queue = [];

    queue.push(scv);
    visited[scv[0]][scv[1]][scv[2]] = 1;

    while(queue.length){
        const [a, b, c] = queue.shift();

        for (const atk of attack){
            const na = Math.max(a - atk[0], 0);
            const nb = Math.max(b - atk[1], 0);
            const nc = Math.max(c - atk[2], 0);

            if(visited[na][nb][nc]) continue;
            queue.push([na, nb, nc]);
            visited[na][nb][nc] = visited[a][b][c] + 1;        
        }
    }
    console.log(visited[0][0][0] - 1);
}

answer();