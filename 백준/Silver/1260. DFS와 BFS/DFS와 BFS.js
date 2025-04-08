const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
// const input = fs.readFileSync('./input.txt').toString().trim().split('\n');

const [N, M, V] = input[0].split(' ').map((e) => +e);
const adj = Array.from({ length: N + 1 }, () => []);
const visited = Array.from({ length: N + 1 }, () => 0);

input.slice(1).map(e => e.split(' ').map(Number)).map((e) => {
  adj[e[0]].push(e[1])
  adj[e[1]].push(e[0])
});

adj.forEach(arr => arr.sort((a, b) => a - b));

const dfs = (here) => {
  visited[here] = 1;

  // 줄바꿈 없이 출력 
  process.stdout.write(here + ' ');

  for (let there of adj[here]){
    if(visited[there]) continue;
    dfs(there);
  }
  return;
}

const bfs = (start) => {
  visited[start] = 1;
  let q = [];
  q.push(start);

  while(q.length !== 0){
    const here = q.shift();
    process.stdout.write(here + ' ');
    
    for (let there of adj[here]){
      if(visited[there]) continue;

      visited[there] = 1;
      q.push(there);
    }
  }
  return;
}

const answer = () => {
  dfs(V);
  visited.fill(0);
  console.log('');
  bfs(V);
}

answer();