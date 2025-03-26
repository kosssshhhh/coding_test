function solution(x, n) {    
    answer = Array(n).fill(x).map((a, i) => a * (i+1));
    
    return answer;
}