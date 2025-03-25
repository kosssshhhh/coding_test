function solution(n) {
    var answer = [];
    
    String(n).split('').reverse().forEach(e => answer.push(+e));
    
    return answer;
}