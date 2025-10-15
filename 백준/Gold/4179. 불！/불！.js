const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const [R, C] = input[0].split(' ').map(Number);
const a = input.slice(1).map(line => line.split(''));

const f_visited = Array.from({length: R}, () => Array(C).fill(Infinity));
const j_visited = Array.from({length: R}, () => Array(C).fill(0));

const dir = [[-1, 0], [0, 1], [1, 0], [0, -1]];
let ret = 0;

const queue = [];
const fire = [];
let jh;

for (let i = 0; i< R; i++){
  for (let j = 0; j<C; j++){
    if(a[i][j] === 'F'){
      queue.push([i, j]);
      f_visited[i][j] = 1;
    }else if(a[i][j] === 'J'){
      jh = [i, j];
    }
  }
}

function answer() {
  while(queue.length) {
    const [y, x] = queue.shift();
    
    for (const [dy, dx] of dir){
      let ny = y + dy, nx = x + dx;

      if(ny < 0 || nx < 0 || ny >=R || nx >= C || f_visited[ny][nx] !== Infinity || a[ny][nx] === '#') continue;
      f_visited[ny][nx] = f_visited[y][x] + 1; 
      queue.push([ny, nx]);
    } 
  }

  queue.push(jh);
  j_visited[jh[0]][jh[1]] = 1;
  
  while(queue.length){
    const [y, x] = queue.shift();

    if(y === 0 || x === 0 || y === R-1 || x === C-1){
      ret = j_visited[y][x];
      break;
    }

    for (const [dy, dx] of dir){
      let ny = y + dy, nx = x + dx;

      if(ny < 0 || nx < 0 || ny >=R || nx >= C || j_visited[ny][nx] || a[ny][nx] === '#') continue;
      if(f_visited[ny][nx] <= j_visited[y][x] + 1) continue;

      j_visited[ny][nx] = j_visited[y][x] + 1;
      queue.push([ny, nx]);
    }
  }
  
  console.log(ret ? ret : 'IMPOSSIBLE');

}

answer();

// 불, 지훈 위치 확인
// 불 먼저 BFS
// 지훈 BFS하면서 불보다 작다는 조건
