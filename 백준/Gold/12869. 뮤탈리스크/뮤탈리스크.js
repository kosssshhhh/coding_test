const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const N = Number(input[0]);

const arr = input[1].split(' ').map(e => {
  return Number(e) 
});

while(arr.length < 3) arr.push(0);

const dealing = [
  [9, 3, 1],
  [9, 1, 3],
  [3, 9, 1],
  [3, 1, 9],
  [1, 9, 3],
  [1, 3, 9],
]

const visited = Array.from({length: 64}, () => Array.from({length: 64}, () => Array(64).fill(0)));

const queue = [];
queue.push([arr[0], arr[1], arr[2]]);
visited[arr[0]][arr[1]][arr[2]] = 1;

while(queue.length){
  const [a, b, c] = queue.shift();
  
  for (let d of dealing){
    const na = Math.max(0, a - d[0]);
    const nb = Math.max(0, b - d[1]);
    const nc = Math.max(0, c - d[2]);

    if(visited[na][nb][nc] !== 0) continue;
    visited[na][nb][nc] = visited[a][b][c] + 1;
    queue.push([na, nb, nc]);
  }
}

console.log(visited[0][0][0] - 1);
