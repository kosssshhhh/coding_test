const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const N = Number(input[0]);
const parents = input[1].split(' ').map(Number);
const M = Number(input[2]);

const adj = Array.from({length: N}, () => []);
let root;

parents.forEach((node, i) => {
    if(node === -1) root = i;
    else adj[node].push(i);
})

const go = (here) => {
    let cnt = 0, ret = 0;

    for(const there of adj[here]){
        if(M === there) continue;

        cnt ++;
        ret += go(there);
    }
    
    if(cnt === 0) return 1;

    return ret;
}

const answer = () => {
    if(M == root){
        console.log(0);
    }else{
        console.log(go(root));
    }
    
}

answer();