const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const answer = (input) => {
    let ret = 0, curr = 0;
    
    input.map((e) => {
        const [o, i] = e.split(' ').map(e => Number(e));
        curr += i - o;
        ret = Math.max(ret, curr);
    })

    return ret;
}

console.log(answer(input));