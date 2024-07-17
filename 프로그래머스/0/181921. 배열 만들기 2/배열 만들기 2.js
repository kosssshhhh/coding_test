function solution(l, r) {
    var answer = [];
    
    for(let i=l; i<=r; i++){
        let flag = false;
        
        let strArr = [...String(i)];
        
        for(let j=0; j<strArr.length; j++){
            if(!(strArr[j] === '5' || strArr[j] === '0')){
                flag = false;
                break;
               }
            flag = true;
        }
        
        if(flag){
            answer.push(i);
        }
    }
    
    if(answer.length === 0) answer.push(-1);
    
    return answer;
}