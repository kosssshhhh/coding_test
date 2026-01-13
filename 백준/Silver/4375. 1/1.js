const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n').map(Number);

function answer(){
    input.forEach((n) => {
      let ret = 1, cnt = 1;

      while(true){
        if(ret % n === 0){
            console.info(cnt);
            break;
        }else {
            ret = ret * 10 + 1;
            ret %= n;
            cnt++;
        }
      }
    })
}

answer();