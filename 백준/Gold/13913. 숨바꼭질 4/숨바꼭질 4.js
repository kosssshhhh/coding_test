const [N, K] = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n')[0].split(' ').map(Number);

function answer () {
   const queue = [];
   const visited = Array(100004).fill(0);
   const prev = Array(100004).fill(-1);

   queue.push(N);
   visited[N] = 1; 
    let p = 0;

    while(p < queue.length){
        const here = queue[p++];

        for (const there of [here + 1, here - 1, here * 2]){
            if(there < 0 || there > 100000) continue;
            if(visited[there] === 0 || visited[there] === visited[here] + 1){
                queue.push(there);
                visited[there] = visited[here] + 1;
                prev[there] = here;
            }
        }
    }

    console.log(visited[K] - 1);
    
    let a = K;
    let v = [];
    
    while(a !== -1){
        v.push(a);
        a = prev[a];
    }

    console.log(v.reverse().join(' '));
    
}

answer();