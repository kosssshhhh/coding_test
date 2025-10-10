const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const N = Number(input[0]);
const a = input.slice(1).map(line => line.split(' ').map(Number));

const dp = Array.from({length: N}, () => Array.from({length: N}, () => Array(3).fill(-1)));

const go = (y, x, d) => {
  if(y < 0 || x < 0 || y >= N || x >= N || a[y][x]) return 0;
  if(d === 1){
    if(a[y - 1][x] || a[y][x - 1]) return 0;
  }

  if(y === N - 1 && x === N - 1) return 1;

  if(dp[y][x][d] !== -1) return dp[y][x][d];
  let ret = 0;

  if(d === 0){
    ret += go(y, x + 1, 0);
    ret += go(y + 1, x + 1, 1);
  }else if(d === 1){
    ret += go(y, x + 1, 0);
    ret += go(y + 1, x + 1, 1);
    ret += go(y + 1, x, 2);
  }else if(d === 2){
    ret += go(y + 1, x + 1, 1);
    ret += go(y + 1, x, 2);
  }

  dp[y][x][d] = ret;
  return ret;
}

console.log(go(0, 1, 0));

