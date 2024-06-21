function solution(str1, str2) {
    var answer = '';
    let i = 0;
    
    while(true){
        if(str1[i]){
            answer +=str1[i]
        }
        if(str2[i]){
            answer+=str2[i]
        }
        if(str1[i]===undefined && str2[i]===undefined){
            break;
        }
        i++;
    }
    
    return answer;
}