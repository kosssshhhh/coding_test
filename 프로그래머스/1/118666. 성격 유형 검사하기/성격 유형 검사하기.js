function solution(survey, choices) {    
    const MBTI = {};
    const types = ['RT', 'CF', 'JM', 'AN'];
    
    types.forEach(type => type.split('').forEach(c => MBTI[c] = 0));

    choices.forEach((choice, index) => {
        const [l, r] = survey[index];
        
        MBTI[choice > 4 ? r : l] += Math.abs(choice - 4);
    })
    
    return types.map(([a, b]) => MBTI[b] > MBTI[a] ? b : a).join("");
}
                   
