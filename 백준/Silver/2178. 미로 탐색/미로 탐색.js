const fs = require('fs');
// const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, m] = input[0].split(' ').map(Number);
const map = input.slice(1).map(line => line.split('').map(Number));

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];
const dist = Array.from({length: n}, () => Array(m).fill(0));

const answer = (n, m, map)=> {
    const queue = [[0, 0]];

    dist[0][0] = 1;

    queue.push([0, 0]);
    while(queue.length){
        const [y, x] = queue.shift();
        
        for (let i=0; i<4; i++){
            const ny = y + dy[i];
            const nx = x + dx[i];

            if(ny < 0 || nx < 0 || ny >=n || nx >=m || dist[ny][nx] !== 0 || map[ny][nx] === 0)continue;

            dist[ny][nx] = dist[y][x] + 1;
            queue.push([ny, nx]);
        }
    }
    
    return dist[n-1][m-1];
}

console.log(answer(n, m, map));
