function solution(arr) {
    var answer = 0;
    
    return arr.reduce((acc, curr) => acc + curr, 0) / arr.length;
    
}