const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const arr = input.slice(1).map(e => e.split(' ').map(e => Number(e)));

const answer = (arr) => {
    let ret = 0;
    arr.sort((a, b) => a[0] - b[0]);
    let [l, r] = arr[0];
    arr = arr.slice(1);
    
    for (let [start, end] of arr){
        if(start <= r && r < end) r = end;
        else if(r < start){
            ret += r - l;
            l = start, r = end;
        }
    }
    ret += r - l;
    return ret;
}

console.log(answer(arr));