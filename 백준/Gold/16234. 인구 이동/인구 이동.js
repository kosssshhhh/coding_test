const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const [N, L, R] = input[0].split(' ').map(Number);
const a = input.slice(1).map(line => line.split(' ').map(Number));

const dir = [[-1, 0], [0, 1], [1, 0], [0, -1]];
let visited = Array.from({length: N}, () => Array(N).fill(0));
let v = [];
let ret = 0;

function dfs(y, x) {
  visited[y][x] = 1; 
  let ret = a[y][x];
  v.push([y, x]);
  
  for (const [dy, dx] of dir){
    let ny = y + dy;
    let nx = x + dx;

    if(ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) continue;
    const dist = Math.abs(a[ny][nx] - a[y][x]);

    if(L <= dist && dist <= R){
      ret += dfs(ny, nx);
    }
  }

  return ret;
}

function answer() {
  while(true){
    let flag = false;
    visited = Array.from({length: N}, () => Array(N).fill(0));

    for (let i = 0; i < N; i++){
      for (let j = 0; j < N; j++){
        if(visited[i][j]) continue;

        v = [];

        let sum = dfs(i, j);
        if(v.length <= 1) continue;
  
        // 인구 이동
        for(const [y, x] of v){
          a[y][x] = Math.floor(sum / v.length);
        }
        
        flag = true;
      }
    }

    if(!flag) break;
    ret++;
  }

  console.log(ret);
  

}

answer();


// 두 나라의 인구 차이 L <= a <= R
// connected component
// 