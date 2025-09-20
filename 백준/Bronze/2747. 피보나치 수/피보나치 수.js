const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const N = Number(input[0]);

const fibo = (n, memo = {}) => {
  if(n <= 2) return 1;

  if(n in memo) return memo[n];

  return memo[n] = fibo(n - 1, memo) + fibo(n - 2, memo);
}

const answer = () => {
  console.log(fibo(N));
}

answer();