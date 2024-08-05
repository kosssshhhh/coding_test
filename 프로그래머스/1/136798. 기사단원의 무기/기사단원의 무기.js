function solution(number, limit, power) {
    let answer = 0;
    let arr = [];
    
    // 약수의 개수 구하기
    for(let i=1; i<=number; i++){
        let cnt = 0;
        for (let j=1; j<=Math.sqrt(i); j++){

            if(i % j === 0){
                cnt++;
                if(j**2 !== i) cnt++;
            }
            if(cnt > limit) break;
        }
        arr.push(cnt);
    }
    
    // limit 보다 큰 값 색출
    arr.forEach((a, i)=>{
        if(a > limit) arr[i] = power;
    })
    
    // 총합
    answer = arr.reduce((a, c)=> a + c)
    
    return answer;
}