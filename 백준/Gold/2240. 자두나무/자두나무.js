const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const [T, W] = input[0].split(' ').map(Number);
const a = input.slice(1).map(Number);

const dp = Array.from({length: T+1}, () => Array.from({length: W+1}, () => Array(2).fill(-1)));

function go(t, w, idx){
  // 기저사례
  if(t === T) return 0;
  if(w < 0) return -Infinity;

  // 메모이제이션
  if(dp[t][w][idx] !== -1) return dp[t][w][idx];
  let ret = 0;

  // 로직
  ret = Math.max(go(t + 1, w, idx), go(t + 1, w - 1, idx ^ 1)) + (a[t] === idx + 1);
  dp[t][w][idx] = ret;

  return ret;
}

function answer (){
  console.log(Math.max(go(0, W, 0), go(0, W - 1, 1)));
}

answer();