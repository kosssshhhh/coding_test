const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const [T, W] = input[0].split(' ').map(Number);
const arr = input.slice(1).map(Number);

const dp = Array.from({length: 1004}, () => Array.from({length: 35}, () => Array(2).fill(-1)));

function go(t, w, tree){
  if(w > W) return -Infinity;
  if(t === T) return 0;

  if(dp[t][w][tree] !== -1) return dp[t][w][tree];
  
  ret = Math.max(go(t + 1, w, tree), go(t + 1, w + 1, tree ^ 1)) + (arr[t] - 1 === tree);
  dp[t][w][tree] = ret;

  return ret;
}

function answer() {
  console.log(Math.max(go(0, 0, 0), go(0, 1, 1)));
}

answer();

// 완탐이 안된다. -> dp
// memo 
// 1. 어느 나무 아래,
// 2. 몇 초 인지
// 3. 움직임 몇번 남았는지
// 값은 자두 개수
