const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
// const input = fs.readFileSync('./input.txt').toString().trim().split('\n');

const arr = input.slice(1).map(Number);

const solution = (arr) => {
  let mx = 0;
  let ret = 0;
  arr.reverse();

  arr.forEach(e => {
    if(mx < e){
      ret++;
      mx = e;
    }
  })
  return ret;
}

console.log(solution(arr));