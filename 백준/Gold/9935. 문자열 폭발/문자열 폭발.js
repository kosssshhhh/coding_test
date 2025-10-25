const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const [s, target] = input;

function answer(){
    const stk = [];

    for (let i = 0; i < s.length; i++){
        stk.push(s[i]);
        
        if(stk.length >= target.length && stk[stk.length - 1] === target[target.length - 1]){
            let str = '';
            for (let j = 0; j < target.length; j++){
                str += stk[stk.length - 1];
                stk.pop();
            }

            str = str.split('').reverse().join('');

            if(target !== str){
                for (let k = 0; k < str.length; k++){
                    stk.push(str[k]);
                }
            }
        }
    }

    console.log(stk.length ? stk.join('') : 'FRULA');
}

answer();