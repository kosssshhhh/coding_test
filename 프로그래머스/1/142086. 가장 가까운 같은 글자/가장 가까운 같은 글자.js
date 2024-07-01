function solution(s) {
    var answer = [];
    
    s.split('').forEach((a, idx)=>{
        res = -1
        
        for(let i=0; i<idx; i++){
            if(a === s[i]) res = idx-i;
            
        }
        answer.push(res)
    })
    
    return answer;
}