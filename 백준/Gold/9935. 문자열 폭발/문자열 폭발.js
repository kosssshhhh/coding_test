const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const [str, target] = input;

function answer(){
   const stk = [];

   for (const c of str){
    stk.push(c);

    if(stk.length >= target.length && stk[stk.length - 1] === target[target.length - 1]){
        let s = "";

        for (let i = 0; i < target.length; i++){
            s += stk[stk.length - 1];
            stk.pop();
        }

        s = s.split('').reverse().join('');
        
        if(s !== target){
            for (const c2 of s){
                stk.push(c2);
            }
        }
    }
    
   }

   if(stk.length){
    console.log(stk.join(''));
   }else {
    console.log("FRULA");
   }
}

answer();