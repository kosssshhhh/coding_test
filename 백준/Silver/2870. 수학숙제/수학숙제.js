const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

const words = input.slice(1);

const normalizeNumber = (s) => {
    let num = s.replace(/^0+/,'');
    return num === '' ? '0' : num;
}

const solve = (words) => {
    const numbers = [];
    
    words.forEach(word =>{
        let currentNumber = '';

        for (const char of word){
            if(char >= '0' && char <= '9'){
                currentNumber += char;
            }else {
                if(currentNumber) {
                    numbers.push(normalizeNumber(currentNumber));
                    currentNumber = '';
                }
            }
        }
        if(currentNumber){
            numbers.push(normalizeNumber(currentNumber));
        }
    })
    
    numbers.sort((a, b) => {
    // 길이를 기준으로 정렬 (우선순위 1)
    if (a.length !== b.length) {
        return a.length - b.length;
    }
    // 길이가 같다면 BigInt로 숫자 크기 비교
    return BigInt(a) > BigInt(b) ? 1 : -1;
});

    numbers.forEach(num => console.log(num));
}

solve(words);