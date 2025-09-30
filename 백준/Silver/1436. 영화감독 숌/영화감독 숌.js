const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const N = Number(input[0]);

const answer = () => {
    let num = 666, ret = 0;
    
    while(true){
        if(num.toString().includes('666')){
            ret++;
            if(ret === N){
                console.log(num);
                return;
            }
        }
        num++;
    }
}

answer();