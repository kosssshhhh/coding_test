const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');
// const input = fs.readFileSync('./input.txt').toString().split('\n');

const n = Number(input[0]);
const map = input.slice(1).map(line => line.split(''));

const check = (y, x, size, map) => {
    for (let i=y; i<y+size; i++){
        for (let j=x; j<x+size; j++){
            if(map[y][x] !== map[i][j]) return false;
        }
    }
    return true;
}

const quad = (y, x, size, map) => {
    let ret = "";
    
    if(n === 1 || check(y, x, size, map)){
        ret += map[y][x];
    }else{
        ret += "(";
        ret += quad(y, x, size/2, map);
        ret += quad(y, x+size/2, size/2, map);
        ret += quad(y+size/2, x, size/2, map);
        ret += quad(y+size/2, x+size/2, size/2, map);
        ret += ")";
    }

    return ret;
}

const answer = (n, map) => {
    console.log(quad(0, 0, n, map));
}

answer(n, map);