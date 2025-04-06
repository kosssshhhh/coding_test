const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
// const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const [n, m] = input[0].split(' ').map(Number);

const count_value = (a, b) => {
  let ret = 0;
  let temp = b;

  while(temp <= a) {
    ret += Math.floor(a / temp); // JS에서는 Math.floor()를 사용해야 함  
    temp *= b;
  }
  return ret;
}

const answer = (n, m) => {
  const cnt_5 = count_value(n, 5) - count_value(m, 5) - count_value(n - m, 5);
  const cnt_2 = count_value(n, 2) - count_value(m, 2) - count_value(n - m, 2);
  
  return Math.min(cnt_5, cnt_2);
}

console.log(answer(n, m));
