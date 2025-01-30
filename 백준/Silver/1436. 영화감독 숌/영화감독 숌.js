const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim();
// const input = fs.readFileSync('./input.txt').toString().split('\n');
const n = Number(input);


const answer = (n) => {
    let num = 666;
    let ret = 0;

    while(true){        
        if(String(num).includes('666')){
            ret++;
            if(ret === n){
                console.log(num);
                break;
            }
        }
        num++;
    }
}
answer(n);