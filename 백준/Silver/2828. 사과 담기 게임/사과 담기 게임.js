const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');
const [N, M] = input[0].split(' ').map(Number);
const apples = input.slice(2).map(Number);

function answer (N, M, apples){
    let l = 1, r = l + M - 1, ret = 0;

    apples.forEach(apple => {
        if(r < apple){
            const dist = apple - r;
            r = apple;
            l += dist;
            ret += dist;
        }else if(apple < l){
            const dist = l - apple;
            l = apple;
            r -= dist;
            ret += dist;
        }
    })

    return ret;
}

console.log(answer(N, M, apples));