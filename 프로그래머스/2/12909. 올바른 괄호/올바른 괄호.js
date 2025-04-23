function solution(s){
    let ret = true;
    const stk = [];
    
    for (let i = 0; i < s.length; i++){
        if(stk.length > 0 && stk[stk.length - 1] == '(' && s[i] == ')') stk.pop();
        else stk.push(s[i]);
    }
    
    ret = stk.length === 0 ? true : false;

    return ret;
}