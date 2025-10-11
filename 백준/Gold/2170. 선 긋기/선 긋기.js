const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const N = Number(input[0]);
const arr = input.slice(1).map(line => line.split(' ').map(Number));

arr.sort((a, b) => {
  return a[0] - b[0];
})

let from = arr[0][0], to = arr[0][1];
let ret = 0;

for (let i = 1; i < N; i++){
  let [s, e] = arr[i];
  
  if(s < to && to < e){
    to = e;
  }else if(to <= s){
    ret += to - from;
    from = s;
    to = e;
  }
}

ret += to - from;

console.log(ret);
