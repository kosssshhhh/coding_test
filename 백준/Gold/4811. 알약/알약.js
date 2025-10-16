const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n').map(Number);

const dp = Array.from({length: 34}, () => Array(34).fill(0));

function go(W, H){
  // 기저 사례
  if(W == 0 && H == 0) return 1;

  if(dp[W][H]) return dp[W][H];
  ret = 0;

  ret += W === 0 ? 0 : go(W - 1, H + 1);
  ret += H === 0 ? 0 : go(W, H - 1);

  dp[W][H] = ret;
  return ret;
}

function answer() {
  for (const n of input){
    if(n === 0) return ;

    console.log(go(n, 0));
  }
}

answer();

