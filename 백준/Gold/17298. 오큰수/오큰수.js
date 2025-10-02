const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const n = Number(input[0]);
const numbers = input[1].split(' ').map(Number);

const answer = () => {
    const stk = [];
    const ret = Array(n).fill(-1);
    
    for (let i = 0; i < n; i++){
        while(stk.length > 0 && numbers[stk[stk.length - 1]] < numbers[i]){
            ret[stk[stk.length - 1]] = numbers[i];
            stk.pop();
        }
        stk.push(i);
    }

    console.log(ret.join(' '));
}

answer();