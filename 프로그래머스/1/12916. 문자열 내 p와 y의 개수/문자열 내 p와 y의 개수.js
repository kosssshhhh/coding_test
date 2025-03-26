function solution(s){
    let p_cnt = 0, y_cnt = 0;
    
    s.split('').forEach(e => {
        e === 'p' || e ==='P' ? p_cnt++ : null;
        e === 'y' || e === 'Y' ? y_cnt++ : null;
    })
    
    return p_cnt === y_cnt;
}