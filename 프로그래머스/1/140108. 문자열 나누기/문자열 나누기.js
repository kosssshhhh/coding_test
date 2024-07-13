function solution(s) {
    let answer = 0;
    let x_count = 0;
    let else_count = 0;
    let idx = 0; 
    
    while(idx < s.length){
        let x = s[idx];
        
        for(let i=idx; s.length; i++){
            if(x === s[i]){
                x_count++;
            }else{
                else_count++;
            }
            
            if(x_count === else_count){
                idx = i+1;
                answer ++;
                break;
            }
        }
    }
    
    return answer;
}