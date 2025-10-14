const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const [n, m] = input[0].split(' ').map(Number);
const a = input.slice(1).map(line => line.split(''));

const dir = [[-1, 0], [0, 1], [1, 0], [0, -1]];
const visited = Array.from({length: n}, () => Array(m).fill(0));
const dp = Array.from({length: n}, () => Array(m).fill(-1));

function go (y, x) {
  if(y < 0 || x < 0 || y >= n || x >= m || a[y][x] === 'H') return 0;
  if(visited[y][x]){
    console.log(-1);
    process.exit(0);
  }

  if(dp[y][x] !== -1) return dp[y][x];
  let ret = 0;

  visited[y][x] = 1;
  for (const [dy, dx] of dir)  {
    let ny = y + dy * a[y][x], nx = x + dx * a[y][x];

    ret = Math.max(go(ny, nx) + 1, dp[y][x]);
    dp[y][x] = ret;
  }
  visited[y][x] = 0;

  return ret;
}

function answer() {
  console.log(go(0, 0));
}

answer();