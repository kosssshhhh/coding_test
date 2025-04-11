const direction = {
    'U': [1, 0],
    'D': [-1, 0],
    'R': [0, 1],
    'L': [0, -1]
};

const makeSet = (a, b, c, d, visited) => {
    visited.add(`${a},${b},${c},${d}`);
    visited.add(`${c},${d},${a},${b}`);
}

const checkSet = (a, b, c, d, visited) => {
    return visited.has(`${a},${b},${c},${d}`);
}

function solution(dirs) {
    let ret = 0;  
    let y=5, x=5;
    
    const visited = new Set();
    
    for (const dir of dirs){
        const [dy, dx] = direction[dir];
        const [ny, nx] = [y + dy, x + dx];
        
        const isIn = ny <= 10 && nx <= 10 && ny >= 0 && nx >= 0;
        if(!isIn) continue;
        
        if(!checkSet(y, x, ny, nx, visited)){
            ret++;
            makeSet(y, x, ny, nx, visited);
        }
        y = ny, x = nx;
    }
    
    return ret;
}