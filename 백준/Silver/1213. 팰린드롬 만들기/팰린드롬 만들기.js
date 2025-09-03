const input = require('fs').readFileSync(process.platform === "linux" ? '/dev/stdin' : './input.txt').toString().trim().split('');

const cnt = Array(30).fill(0);

function answer (input) {
    for(const c of input){
        cnt[c.charCodeAt(0) - 65]++;
    }
    let start = "", mid= "", last = "";
    let flag = 0;

    for (let i=0; i<30; i++){
        for(let j=0; j<cnt[i] - 1; j+=2){
            start += String.fromCharCode(65+i);
            last = String.fromCharCode(65+i) + last;
        }

        if(cnt[i] & 1){
            flag++;
            if(flag > 1){
                console.log("I'm Sorry Hansoo");
                return;
            }
            mid += String.fromCharCode(65+i);
        }
    }
    console.log(start+ mid + last);
}
answer(input);