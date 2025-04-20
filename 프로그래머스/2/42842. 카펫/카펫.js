function solution(brown, yellow) {
    const sum = brown + yellow;
    let mx = 0;
    
    for (let i = 3; i <= Math.sqrt(sum); i++){
        if(sum % i === 0 && (i - 2) * (sum / i - 2) === yellow) mx = i;
    }
    
    const answer = [sum / mx, mx];
    
    
    return answer;
}