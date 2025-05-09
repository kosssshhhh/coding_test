const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, m] = input[0].split(' ').map(e => Number(e));
const arr = input[1].split(' ').map(e => Number(e));

const answer = (n, m, trees) => {
    let mx = 0, ret = 0;
    trees.forEach(tree => mx = Math.max(mx,tree));

    let l = 0, r = mx;

    const bs = (trees, h) => {
        const arr = trees.map(tree => tree - h);
        
        return arr.reduce((acc, curr) => {
            if(curr < 0) return acc;
            else return acc + curr;
        }, 0)
    }

    while(l <= r){
        let mid = Math.floor((l + r) / 2);
        
        if(bs(trees, mid) >= m){
            l = mid + 1;
            ret = mid;
        }else {
            r = mid - 1;
        }
    }
    return ret;
}

console.log(answer(n, m, arr));