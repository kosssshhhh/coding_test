const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n').map(e => Number(e));

const answer = (input) => {
   const psum = Array(11).fill(0);

   for (let i = 0; i<input.length; i++){
        psum[i+1] = psum[i] + input[i];
   }

   let ret = 0;
   let mx = 1e9;


   for(let i=0; i<input.length+1; i++){

    if(Math.abs(100 - psum[i]) <= mx){
        
        if(Math.abs(100-psum[i]) == mx){
            ret = Math.max(ret, psum[i]);
        }else {
            ret = psum[i];
        }
        mx = Math.abs(100-psum[i]);
    }
   }

   return ret;
}

console.log(answer(input));