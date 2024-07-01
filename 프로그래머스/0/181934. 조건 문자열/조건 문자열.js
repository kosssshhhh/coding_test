function solution(ineq, eq, n, m) {
    var answer = 0;
    
    switch(eq){
        case '=':
            if(ineq === '<'){
                answer = n<=m ? 1 : 0;
            }else {
                answer = n>=m ? 1 : 0;
            }
            break;
            
        case '!':
            if(ineq === '<'){
                answer = n < m ? 1 : 0;
            }else{
                answer = n > m ? 1 : 0;
            }
            break;
            
        default:
            break;
    }
    
    return answer;
}