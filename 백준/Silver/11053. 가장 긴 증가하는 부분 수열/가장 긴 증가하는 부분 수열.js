const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const arr = input[1].split(' ').map(e => Number(e));

function answer(arr){
    const n = arr.length;
    const lis = Array(n).fill(1);

    for (let i = 1; i<n; i++){
        for (let j = 0; j< i; j++){
            if(arr[j] < arr[i]){
                lis[i] = Math.max(lis[i], lis[j] + 1);
            }
        }
    }
    return Math.max(...lis);
}

console.log(answer(arr));