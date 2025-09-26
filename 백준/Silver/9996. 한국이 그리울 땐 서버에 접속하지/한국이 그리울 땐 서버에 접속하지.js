const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const N = input[0];
const pattern = input[1];
const arr = input.slice(2);

const answer = () => {
    const [pre, suf] = pattern.split('*');

    arr.forEach(s => {
        if(pre.length + suf.length > s.length){
            console.log("NE");
        }else{
            if(s.substring(0, pre.length) === pre && s.substring(s.length - suf.length) === suf){
                console.log("DA");
            }else{
                console.log("NE");
                
            }
        }
    })
    
}

answer();