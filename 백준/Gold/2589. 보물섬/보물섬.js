const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const [N, M] = input[0].split(' ').map(Number);
const v = [];
const a = input.slice(1).map((line, i) => line.split('').map((e, j) => {
  if(e === 'W'){
    return 0;
  }else{
    v.push([i, j]);
    return 1;
  }
}))

const dir = [[-1, 0], [0, 1], [1, 0], [0, -1]];

const answer = () => {
  let ret = 0;

  for (let t = 0; t < v.length; t++){ 
    const q = [];
    const visited = Array.from({length: N}, () => Array(M).fill(0));

    q.push(v[t]);
    visited[v[t][0]][v[t][1]] = 1;

    while(q.length > 0){
      let [y, x] = q[0];
      q.shift();
      
      for (const [dy, dx] of dir){
        let [ny, nx] = [y + dy, x + dx];

        if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;
        if(a[ny][nx] == 1){
          visited[ny][nx] = visited[y][x] + 1;
          q.push([ny, nx]);
        }
      }
    }

    for (let i = 0; i < N; i++){
      for (let j = 0; j < M; j++){
        ret = Math.max(ret, visited[i][j])
      }
    }
  }
  console.log(ret - 1);
  
}

answer();