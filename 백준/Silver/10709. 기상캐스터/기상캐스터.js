const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');
// const input = fs.readFileSync('./input.txt').toString().split('\n');

const [n, m] = input[0].split(' ').map(a => Number(a));
const map = input.slice(1).map((line, i) => line.split(''));

const go = (y, x, visited) => {
    let ny = y;
    let nx = x + 1;

    if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] !== -1) return;

    visited[ny][nx] = visited[y][x] + 1;
    go(ny, nx, visited);
}

const solve  = (n, m, map) => {
    const visited = Array.from({length: n}, () => Array(m).fill(-1));

    map.forEach((line, i) => {
        line.forEach((a, j) => {
            if(a === 'c') visited[i][j] = 0;
        })
    })

    for (let i=0; i<n; i++){
        for (let j=0; j<m; j++){
            if(map[i][j] === 'c'){
                go(i, j, visited);
            }
        }
    }

    visited.forEach(line => console.log(line.join(' ')));
}

solve(n, m, map);