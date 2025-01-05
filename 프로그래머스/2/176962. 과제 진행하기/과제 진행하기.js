function solution(plans) {
    let answer = [];
    let stack = [];
    let order = 1;
    
    plans.forEach(e => {
        let a = e[1].split(":");
        e[1] = parseInt(a[0]) * 60 + parseInt(a[1]);
        e[2] = parseInt(e[2]);
    })

    plans.sort((a, b) => a[1] - b[1]);
    console.log(plans);    
    
    for (let i=0; i<plans.length-1; i++){
        let [name1, start1, time1] = plans[i];
        let [name2, start2, time2]=plans[i+1];
        
        if(time1 > start2 - start1){
            // 대기열에 push
            stack.push([name1, time1 - start2 + start1]);
            order++;
        }else if(time1 < start2 - start1){
            // 남은 시간 대기열에 있는거 차감해주기
            let left_time = start2- start1 -time1;
            answer.push(name1);
            
            if(!stack.length) continue;
            
            while(stack.length && left_time>0){
                let [name, time] = stack.pop();
                
                if(left_time >= time){
                    answer.push(name);
                }else if(left_time < time){
                    stack.push([name, time - left_time]);
                }                
                left_time -= time;
            }
        }else {
            answer.push(name1);
        }
    }
    
    answer.push(plans[plans.length-1][0]);
    
    while(stack.length){
        let [name, a, b] = stack.pop();
        answer.push(name);
    }
    
    return answer;
}