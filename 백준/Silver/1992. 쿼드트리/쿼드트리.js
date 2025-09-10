const input = require('fs').readFileSync(process.platform === "linux" ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const n = input[0];
const a = input.slice(1).map(line => line.split(''));

const check = (y, x, len) => {
    const start = a[y][x];
    
    for (let i = y; i < y + len; i++){
        for (let j = x; j< x + len; j++){
            if(start !== a[i][j]) return false;
        }
    }

    return true;
}

const go = (y, x, len) => {
    if(len === 1) return a[y][x];

    if(!check(y, x, len)){
        return '(' + go(y, x, len / 2) + go(y, x + len / 2, len / 2) + go(y + len / 2, x, len / 2) + go(y + len / 2, x + len / 2, len / 2) + ')';
    }
    
    return a[y][x];
}

function answer(n){
    return go(0, 0, n);
}

console.log(answer(n));