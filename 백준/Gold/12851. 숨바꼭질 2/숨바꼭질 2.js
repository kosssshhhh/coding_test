const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const [N, K] = input[0].split(' ').map(Number);
const visited = Array(100004).fill(0);
let cnt = 0;

function answer() {
  const queue = [];

  queue.push(N);
  visited[N] = 1;

  let p = 0;

  while(p < queue.length) {
    const here = queue[p++];

    if(here === K) cnt++;

    for (const there of [here + 1, here - 1, here * 2]){
      if(there < 0 || there > 100000) continue;
      
      if(visited[there] === 0 || visited[there] === visited[here] + 1){
        queue.push(there);
        visited[there] = visited[here] + 1;
      }
    }
  }

  console.log(visited[K] - 1, cnt);
  
}

answer();