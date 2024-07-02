function solution(s, skip, index) {
    let answer = '';

    for(let i=0; i<s.length; i++){
        let currStr = s[i];
        let shift = 0;
        
        while(shift < index){
            currStr = String.fromCharCode(currStr.charCodeAt(0) + 1);
            
            if(currStr > 'z'){
                currStr = 'a'
            }
            
            if(!skip.includes(currStr)){
                shift++
            }
            
        }
        answer += currStr
    }
    return answer;
}

