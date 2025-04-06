const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
// const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const N = +input[0];
const arr = input.slice(1);

const solution = (N, arr) => {
  const mp = new Map();
  let ret = 0;


  arr.forEach((e, i) => {
    if(e === "ENTER"){
      mp.clear();
    }else {
      if(!mp.has(e)){
        mp.set(e, 1);
        ret++;
      }
    }
  })
  
  return ret;
}

console.log(solution(N, arr));