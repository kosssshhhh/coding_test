const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');
// const input = fs.readFileSync('./input.txt').toString().split('\n');

const [n, c] = input[0].split(' ').map(a => Number(a));
const arr = input[1].split(' ').map(a => Number(a));

const answer = (n, c, arr) => {
    const map1 = new Map(); // 등장 횟수
    const map2 = new Map(); // 등장 순서

    arr.forEach((a, i) => (map1[a] = 0));
    arr.forEach((a, i) => {

        map1[a]++;
        
        if(map2[a]){
            // nothing
        }else {
            map2[a] = i+1;
        }
    })

     arr.sort((a, b) => {
        if(map1[a] === map1[b]){
            return map2[a] - map2[b];
        }
        return map1[b] - map1[a];
    })
    let  ret = "";
    arr.forEach(a => {
        ret += a;
        ret += ' ';
    });

    console.log(ret);

}

answer(n, c, arr);