function solution(n) {
    var answer = [];
    
    String(n).split('').forEach(e => answer.push(+e));
    
    answer.reverse();
    
    return answer;
}