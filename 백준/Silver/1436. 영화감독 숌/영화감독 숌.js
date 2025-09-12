const input = require('fs').readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt").toString().trim();

const answer = (n) => {
    let num = 666, ret = 0;

    while(true){
        if(num.toString().includes("666")){
            ret++;
            if(ret === n) {
                return num;
            }
        }
        num++;
    }
    
}

console.log(answer(Number(input)))