const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

let [N, K] = input[0].split(' ').map(Number);

const MAX = 500000;
const visited = Array.from({length: 2}, () => Array(MAX + 1).fill(0));

function answer(){
    if(N === K) {
        console.log(0);
        return;
    }

    let queue = [N];
    visited[0][N] = 1; 
    
    let turn = 1, ok = false;

    while(queue.length){
        K += turn

        if(K > MAX) break;
        if(visited[turn % 2][K]){
            ok = true;
            break;
        }

        let newQueue = [];
        for (let x of queue){
            for (let nx of [x - 1, x + 1, x * 2]){
                if(nx < 0 || nx > MAX || visited[turn % 2][nx]) continue;
                visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1;

                if(nx === K){
                    ok = 1;
                    break;
                }
                newQueue.push(nx);
            }
            if(ok) break;
        }
        if(ok) break;
        
        queue = newQueue;
        turn++;
    }

    if(ok) console.log(turn);
    else console.log(-1);
    
}

answer();