const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const [N, M] = input[0].split(' ').map(Number);
const trees = input[1].split(' ').map(Number);
let mx = 0; 

const check = (h) => {
  return trees.reduce((acc, cur) => acc + Math.max(cur - h, 0), 0) >= M;
}

const answer = () => { 
  let ret = 0; 
  trees.forEach(tree => mx = Math.max(mx, tree));

  let lo = 0, hi = mx;
  
  
  while(lo <= hi){
    const mid = Math.floor((lo + hi) / 2);
    
    if(check(mid)){
        ret = Math.max(ret, mid);
        lo = mid + 1;
    }else{
        hi = mid - 1;
    }
  }

  console.log(ret);
}

answer();