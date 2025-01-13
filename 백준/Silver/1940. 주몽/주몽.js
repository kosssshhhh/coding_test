const fs = require('fs');
// const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const n = Number(input[0]);
const m = Number(input[1]);
const materials = input[2].split(' ').map(Number);

let ret = 0

const combi = (start, arr) =>{
    if(arr.length === 2){
        const sum = materials[arr[0]] + materials[arr[1]];
        if(sum === m) ret++;
        return;
    }

    for (let i = start + 1; i < n; i++) {
        arr.push(i);
        combi(i, arr);
        arr.pop();
    }
}

combi(-1, []);

console.log(ret);