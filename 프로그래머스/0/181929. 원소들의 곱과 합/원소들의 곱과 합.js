function solution(num_list) {
    let answer = 0;
    let sum = 0;
    let cross = 1;
    
    num_list.map((num)=>{
        sum += num;
        cross *= num;
    })
    
    answer = sum * sum > cross ? 1 : 0 
    
    return answer;
}