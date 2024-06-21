function solution(n, m, section) {
    var answer = 0;
    
    var arr = Array(n).fill(true)
    
    section.map((a)=> {
        arr[a] = false
    })
    
    for(let i=0; i<arr.length; i++){
        if(arr[i] === false){
            for(j=0; j<m; j++){
                arr[i+j] = true;
            }
            i += j-1;
            answer+=1;
        }
    }
    
    return answer;
}