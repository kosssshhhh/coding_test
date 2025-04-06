const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
// const input = fs.readFileSync('./input.txt').toString().trim().split('\n');

const N = +input[0];
const arr =input.slice(1).map((v) => v.split(' ').map(Number));

const go = (idx, memo = {}) => {
  if(idx >= N) return 0;

  if(memo[idx]) return memo[idx];

  let max = 0;
  for(let i = idx; i < N; i++) {
    const [day, price] = arr[i];
    if(i + day <= N) {
      max = Math.max(max, price + go(i + day, memo));
    }
  }

  max = Math.max(max, go(idx + 1, memo));

  memo[idx] = max;
  return max;

}

const answer = () => {
  return go(0);
}

console.log(answer(arr));