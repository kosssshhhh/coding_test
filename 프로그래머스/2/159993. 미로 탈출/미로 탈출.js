const INF = 1e9;
const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];
let dist1, dist2;
let sy, sx, ly, lx, ey, ex, n, m;

const bfs = (sy, sx, ey, ex, dist, maps) => {
    const queue = [];
    dist[sy][sx] = 0;
    queue.push([sy, sx]);
    
    while(queue.length){
        let [y, x] = queue.shift();
        
        for (let i=0; i<4; i++){
            let ny = y + dy[i];
            let nx = x + dx[i];
            
            if(ny<0 || nx <0 || ny >=n || nx >= m || dist[ny][nx]!=INF || maps[ny][nx] ==='X') continue;
            dist[ny][nx] = dist[y][x] + 1;
            queue.push([ny, nx]);
        }
    }
}

function solution(maps) {
    n = maps.length;
    m = maps[0].length;
    
    dist1 = Array(n).fill().map((e) => Array(m).fill(INF));
    dist2 = Array(n).fill().map((e) => Array(m).fill(INF));

    maps.forEach((row, i) => {
        for (let j=0; j< row.length; j++){
            if(maps[i][j] === 'S'){
                sy = i;
                sx = j;
            }else if(maps[i][j] === 'L'){
                ly = i;
                lx = j;
            }else if(maps[i][j] === 'E'){
                ey = i;
                ex = j;
            }
        }
    })

    bfs(sy, sx, ly, lx, dist1, maps);
    let ret1 = dist1[ly][lx];
    if(ret1 === INF) return -1; 
    
    bfs(ly, lx, ey, ex, dist2, maps);
    let ret2 = dist2[ey][ex];
    if(ret2 === INF) return -1;
    
    return ret1 + ret2;
}

// BFS 두번
// start -> 레버  && 레버 -> 통로