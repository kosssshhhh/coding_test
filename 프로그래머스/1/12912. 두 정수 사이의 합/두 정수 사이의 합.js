function solution(a, b) {
    let ret = 0;
    
    for(let i=Math.min(a, b); i<=Math.max(a, b); i++) ret += i
    
    return ret;
}