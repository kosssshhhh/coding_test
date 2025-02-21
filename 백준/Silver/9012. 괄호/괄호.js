const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const n = Number(input[0]);
const arr = input.slice(1);

const answer = (n, arr) => {
  arr.map((s) => {
    const stk = [];

    [...s].map((c) => {
      if (c === '(' || stk.length === 0) {
        stk.push(c);
      } else if (c === ')' && stk.length !== 0) {
        if (stk[stk.length - 1] === '(') {
          stk.pop();
        }
      }
    });

    if (stk.length !== 0) {
      console.log('NO');
    } else {
      console.log('YES');
    }
  });
};

answer(n, arr);
