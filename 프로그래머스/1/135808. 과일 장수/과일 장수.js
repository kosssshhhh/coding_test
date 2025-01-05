function solution(k, m, score) {
    let ret = 0;
    
    score.sort((a, b) => b-a);
    // console.log(score)
    let sum = 0;
    for (let i=m-1; i<score.length; i+=m){
        // console.log(score[i]);
        sum += score[i];
    }
    ret = sum * m;
    
    return ret;
}