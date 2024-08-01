function solution(k, score) {
    let result = [];
    let ranks = [];
    
    score.map((s)=>{
        ranks.push(s);
        ranks.sort((a, b) => a - b);

        if(ranks.length > k){
            ranks.shift();
        }

        result.push(ranks[0]);
    })
    
    return result;
}