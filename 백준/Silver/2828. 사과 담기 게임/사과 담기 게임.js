const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');
// const input = fs.readFileSync('./input.txt').toString().split('\n');

const [n, m] = input[0].split(' ').map(a => Number(a));
const apples = input.slice(2).filter(a => a !== '').map(Number);

const answer = (n, m, apples) => {
    let ret = 0;

    const j = apples.length;
    let l = 1;
    let r = l + m - 1;
    
    apples.forEach(apple => {
        // console.log(apple);
        if(apple >= l && apple <= r){
            // 이동 없음
        }
        else if (apple < l) {
            const move = l - apple;
            l -= move;
            r -= move;
            ret += move;
            // console.log(`왼쪽으로 ${move}칸 이동`);
        } else if (apple > r) {
            const move = apple - r;
            l += move;
            r += move;
            ret += move;
            // console.log(`오른쪽으로 ${move}칸 이동`);
        }
    })
    return ret;
}

console.log(answer(n, m, apples));

// js 백준에서 입출력의 중요성에 대해서 알게됨