function solution(numbers) {
    const answer = Array(numbers.length).fill(-1);
    const stk = [];
    
    numbers.forEach((e, i) => {
        while(stk.length > 0 && numbers[stk[stk.length - 1]] < e){
           answer[stk.pop()] = e;
        }
        stk.push(i);
    })
    
    return answer;
}