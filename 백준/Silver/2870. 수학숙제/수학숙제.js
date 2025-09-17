const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const N = Number(input[0]);
const inputs = input.slice(1)

const go = (s) => {
    while(s.length > 0){        
        if(s[0] == '0'){
            s = s.substring(1);
        }else 
            break;
    }

    return s.length === 0 ? '0' : s;
}

const answer = () => {
    const v = new Array();

    inputs.forEach(a => {
        let s = "";
        for(let i = 0; i<a.length; i++){
            if(a[i] >= '0' && a[i] <= '9'){
                s += a[i];
            }else if(s.length > 0){
                v.push(go(s));
                s = "";
            }
        }
        if(s.length > 0){
            v.push(go(s));
        }
    })

    v.sort((a, b) => {
        if(a.length === b.length){
            return a - b;
        }
        return a.length - b.length;
    })

    console.log(v.join('\n'));
}

answer();