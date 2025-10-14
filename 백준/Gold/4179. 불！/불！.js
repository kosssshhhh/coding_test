const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const [R, C] = input[0].split(' ').map(Number);
const a = input.slice(1).map(line => line.split(''));

const dir = [[-1, 0], [0, 1], [1, 0], [0, -1]];

const queue = [];
let jh;
const fire_visited = Array.from({length: R}, () => Array(C).fill(Infinity));
const jihun_visited = Array.from({length: R}, () => Array(C).fill(Infinity));

for (let i = 0; i<R; i++){
  for (let j = 0; j<C; j++){
    if(a[i][j] === 'F') {
      fire_visited[i][j] = 1;
      queue.push([i, j]);
    }else if(a[i][j] === 'J'){
      jihun_visited[i][j] = 1;
      jh = [i, j];
    }
  }
}



function answer() {
  // 불 이동
  while(queue.length){
    const [y, x] = queue.shift();
    
    for (const [dy, dx] of dir){
      let ny = y + dy, nx = x + dx;
      
      if(ny < 0 || nx < 0 || ny >= R || nx >= C || fire_visited[ny][nx] !== Infinity || a[ny][nx] === '#') continue;
      if(a[ny][nx] === '.' || a[ny][nx] === 'J'){
        fire_visited[ny][nx] = fire_visited[y][x] + 1;
        queue.push([ny, nx]);
      }
    }
  }

  // 지훈 이동
  queue.push(jh);
  jihun_visited[jh[0]][jh[1]] = 1;
  while(queue.length){
    const [y, x] = queue.shift();

    if(y === 0 || x === 0 || y === R - 1 || x === C - 1){
      console.log(jihun_visited[y][x]);
      return;
    }

    for (const [dy, dx] of dir){
      let ny = y + dy, nx = x + dx;

      if(ny < 0 || nx < 0 || ny >= R || nx >= C || jihun_visited[ny][nx] !== Infinity || a[ny][nx] === '#' || a[ny][nx] === 'F') continue;
      if(fire_visited[ny][nx] <= jihun_visited[y][x] + 1) continue;
      
      queue.push([ny, nx]);
      jihun_visited[ny][nx] = jihun_visited[y][x] + 1;
    }
  }
  
  
  console.log("IMPOSSIBLE")
}

answer();


// BFS
// 불 먼저 BFS -> 지훈 BFS
// 이동거리가 지훈이가 더 작아야만 이동 가능
// 