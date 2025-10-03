const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const [n, m] = input[0].split(' ').map(Number);
const a = input.slice(1).map(line => line.split(' ').map(Number));

const _house = [], _chicken = [];

let ret = 1e9;

a.forEach((line, i) => line.forEach((e, j) => {
  if(e === 1){
    _house.push([i, j]);
  }else if(e ===2){
    _chicken.push([i, j]);
  }
}))

const chicken_dist = (v) => {
  let ret = 0;
  for (let i = 0; i < _house.length; i++){
    let mn = 1e9;
    for (let j = 0; j < v.length; j++){
      let dist = Math.abs(_house[i][0] - _chicken[v[j]][0]) + Math.abs(_house[i][1] - _chicken[v[j]][1]);
      mn = Math.min(dist, mn);
    }
    ret += mn;
  }
  return ret;
}

const go = (a, v = []) => {
  if(v.length === m){
    // logic
    ret = Math.min(ret, chicken_dist(v));
  }

  for (let i = a + 1; i < _chicken.length; i++){
    v.push(i);
    go(i, v);
    v.pop();
  }
}

const answer = () => {
  go(-1);

  console.log(ret);
  
}

answer();
