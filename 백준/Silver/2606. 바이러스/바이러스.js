const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const N = +input[0];
const adj = Array.from({length: N+1}, () => []);

input.slice(2).map(line => line.split(' ').map(Number)).forEach(([from, to]) => {
  adj[from].push(to);
  adj[to].push(from);
})

let ret = 0;
const dfs = (here, visited = new Set()) => {
  visited.add(here);

  for(let there of adj[here]){
    if(visited.has(there)) continue;
    ret++;
    dfs(there, visited);
  }
  return;
}

const answer = () => {
  dfs(1);
  return ret;
}

console.log(answer());