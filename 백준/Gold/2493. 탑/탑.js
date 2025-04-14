const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const arr = input[1].split(' ').map(Number);

const answer = (towers) => {
  const stk = [];
  const ret = Array.from({length: arr.length}).fill(0);

  towers.forEach((tower, idx) => {
    while(stk.length > 0){
      const [i, e] = stk[stk.length - 1];

      if(e >= tower){
        ret[idx] = i+1;
        break;
      }else stk.pop();
      
    }
    stk.push([idx, tower]);
  })

  console.log(ret.join(' '));
}

answer(arr);