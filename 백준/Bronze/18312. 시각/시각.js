const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, k] = input[0].split(' ');

const to_string2 = (a) => {
  return a / 10 < 1 ? '0' + a : a + '';
}

const check_sec = (sec, k) => {
  let temp = sec;
  let h = Math.floor(temp / (60 * 60));
  temp %= 60 * 60;
  let m = Math.floor(temp / 60);
  temp %= 60;
  
  let s = to_string2(h) + to_string2(m) + to_string2(temp);
  
  return s.includes(k)
}

const answer = (n, k) => {
  let ret = 0;

  let second = 59;
  second += 59 * 60;
  second += n * 60 * 60;

  for (let i=0; i<=second; i++)
    if(check_sec(i, k)) ret ++;
  
  return ret;
}

console.log(answer(n, k));

