function solution(a, b) {
    var answer = 0;
    
    n1 = parseInt(String(a) + String(b))
    n2 = parseInt(String(b) + String(a));
    
    answer = n1 > n2 ? n1 : n2 
    
    return answer;
}