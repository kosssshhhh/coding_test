const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const n = Number(input[0]);
const arr = input[1].split(' ').map(e => Number(e));
const x = Number(input[2]);

function answer (n, arr, target){
    let ret = 0;

    arr.sort((a, b) => a - b);
    // console.log(arr);

    let l = 0, r = arr.length - 1;
    
    while(l < r){
        if(arr[l] + arr[r] > target){
            r--;
        }else if(arr[l] + arr[r] < target){
            l++;
        }else {
            ret++; 
            l++;
        }
    }
    
    return ret;
}

console.log(answer(n, arr, x));