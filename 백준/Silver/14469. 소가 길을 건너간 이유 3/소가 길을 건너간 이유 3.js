const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const N = Number(input[0]);
const a = input.slice(1).map(line => line.split(' ').map(Number));

function answer() {
    a.sort((a, b) =>  a[0] - b[0]);
    
    let ret = 0;

    for (const [start, dur] of a){
        if(ret > start) {
            ret += dur;
        }else {
            ret = start + dur;
        }
    }

    console.log(ret);
}

answer();