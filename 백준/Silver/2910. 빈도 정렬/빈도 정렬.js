const input = require('fs').readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt').toString().trim().split('\n');

const [N, C] = input[0].split(' ').map(Number);
const arr = input[1].split(' ').map(Number);

const answer = () => {
    const cnt = Object.create(null);
    const idx = Object.create(null);

    arr.forEach((a, i) => {
        cnt[a]++;
        if(cnt[a]) cnt[a]++;
        else cnt[a] = 1;
        if(!idx[a]) idx[a] = i + 1;
    })
    
    arr.sort((a, b) => {
        if(cnt[a] === cnt[b]){
            return idx[a] - idx[b];
        }
        return cnt[b] - cnt[a];
    })

    console.log(arr.join(' '));
}

answer();