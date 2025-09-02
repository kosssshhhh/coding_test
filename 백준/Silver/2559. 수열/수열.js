const fs = require("fs");
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, k] = input[0].split(' ').map(a => Number(a));
const temps = input[1].split(' ').map(a => Number(a));

function answer(n, k, temps) {
    const psum = [0];
    let ret = -Infinity;

    for (let i = 1; i <= n; i++){
        psum[i] = psum[i - 1] + temps[i - 1];
    }
    
    for (let i = k; i <= n; i++){
        let sum = psum[i] - psum[i - k];

        ret = Math.max(sum, ret);
    }
    
    console.log(ret);
}

answer(n, k, temps);

