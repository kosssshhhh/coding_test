function solution(a, b) {
    var answer = 0;
    
    n = parseInt(a.toString() + b.toString())
    
    answer = n >= 2*a*b ? n : 2*a*b  
    
    return answer;
}