function solution(a, b) {
    let ret = 0;
    
    let A = a < b ? a : b;
    let B = a < b ? b : a;
    
    for(let i=A; i<=B; i++) ret += i;
    
    return ret;
}