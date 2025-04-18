const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [s, delimeter] = input;

const answer = (s, delimeter) => {
    let ret = 0;
  
  let start = 0;
  let end = s.match(delimeter)

  while(end !== null){
    s = s.substring(end.index + delimeter.length);
    
    ret++;
    start = end.index;
    end = s.match(delimeter);
  }

  return ret;
}

console.log(answer(s, delimeter));