const [N, K] = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split(' ').map(Number);
const visited = Array(100004).fill(0);
const prev = Array(100004).fill(0);

const ret = [];

function answer() {
    const queue = [];
    queue.push(N);
    visited[N] = 1; 
    let p = 0;

    while(p < queue.length){
        const here = queue[p++];

        for (const next of [here + 1, here - 1, here * 2]){
            if(next < 0 || next > 100000) continue;

            if(visited[next] === 0 || visited[next] === visited[here] + 1){
                queue.push(next);
                visited[next] = visited[here] + 1;
                prev[next] = here;
            }
        }
    }

    console.log(visited[K] - 1);

    let temp = K;
    while(temp !== N){
        ret.push(temp);
        temp = prev[temp];
    }
    ret.push(N);

    console.log(ret.reverse().join(' '));
}

answer();