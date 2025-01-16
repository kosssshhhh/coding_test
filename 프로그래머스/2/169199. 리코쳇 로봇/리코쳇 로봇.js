const dy = [1, 0, -1, 0];
const dx = [0, 1, 0, -1];
let sy, sx;
let ey, ex;

function solution(board) {
    const n = board.length;
    const m = board[0].length;
    
   for (let i=0; i<n; i++){
       for (let j=0; j<m; j++){
           if(board[i][j] === 'R'){
               sy = i;
               sx = j;
           }else if(board[i][j] === 'G'){
               ey = i;
               ex = j;
           }
       }
   }
    
    const queue = [[sy, sx]];
    const dist = Array.from({length: n}, () => Array(m).fill(0));
    dist[sy][sx] = 1;
    
    while(queue.length){
        const [y, x] = queue.shift();
        
        if(board[y][x] === 'G') return dist[y][x]-1;
        
        for (let i=0; i<4; i++){
            let ny = y;
            let nx = x;
            
            while(true){
                const nextY = ny + dy[i];
                const nextX = nx + dx[i];
                
                if(nextY < 0 || nextX < 0 || nextY >= n || nextX >=m || board[nextY][nextX] === 'D') break;
                
                ny = nextY;
                nx = nextX;
            }
            
            if(!dist[ny][nx]){
                dist[ny][nx] = dist[y][x] + 1;
                queue.push([ny, nx]);
            }
        }
    }
    
    return -1;
}

// 1. 쭉 가는거 구현
// 2. DP 구현
// 3. 최소?
