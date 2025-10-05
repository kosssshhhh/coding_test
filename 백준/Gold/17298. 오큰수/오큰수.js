const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const N = Number(input[0]);
const arr = input[1].split(' ').map(Number);

const answer = () => {
  const stk = [];
  const ret = Array(N).fill(-1);

  for (let i = 0; i < N; i++){
    while(stk.length > 0 && arr[stk[stk.length - 1]] < arr[i]){
      ret[stk[stk.length - 1]] = arr[i];
      stk.pop();
    }
    stk.push(i);
  }

  console.log(ret.join(' '));
  
}

answer();