const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const n = Number(input[0]);
const pat = input[1];
const strings = input.slice(2);

function answer(n, pat, strings) {
    const [pre, suf] = pat.split('*');

    strings.forEach((s) => {
        if(pre.length + suf.length > s.length){
            console.log('NE');
        }else {
            if(s.substring(0, pre.length) === pre && s.substring(s.length - suf.length, s.length) === suf){
                console.log('DA');
            }else{
                console.log("NE");
            }
        }
    })
    
}

answer (n, pat, strings);