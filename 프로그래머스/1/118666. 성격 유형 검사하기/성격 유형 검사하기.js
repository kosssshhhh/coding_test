function solution(survey, choices) {
    let answer = '';
    
    const obj = {'R': 0, 'T': 0, 'C': 0, 'F': 0, 'J': 0, 'M': 0, 'A': 0, 'N': 0};
    const n = survey.length;
    const arr = [['R', 'T'], ['C', 'F'], ['J', 'M'], ['A', 'N']];
    
    for(let i=0; i<n; i++){
        const [first, second] = survey[i];
        const c = choices[i];
        
        if(c > 4){
            obj[second] += c - 4;
        }else if(c < 4){
            obj[first] += 4 - c
        }
    }
    
    arr.forEach(e => {
        const [type1, type2] = e;
        
        obj[type1] < obj[type2] ? answer += type2 : answer += type1;
    })
    
    
    return answer;
}