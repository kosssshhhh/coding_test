function solution(today, terms, privacies) {
    let answer = [];
    
    let day = new Date(today)
    let termObj = {};
    terms.map((term, idx)=>{
        termObj[term.split(' ')[0]] = term.split(' ')[1];
    })
    
    privacies.map((privacy, idx)=>{
        let [date, term] = privacy.split(' ');
        
        date = new Date(date);
        
        date.setMonth(date.getMonth() + parseInt(termObj[term]));
        
        if(day >= date){
            answer.push(idx + 1);
        }
    })
   
    return answer;
}