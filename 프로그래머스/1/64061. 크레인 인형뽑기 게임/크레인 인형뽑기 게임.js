function solution(board, moves) {
    let answer = 0;
    const stk = [];
    const n = board[0].length;
    
    const getNumberInBoard = (m) => {
        for(let i=0; i<n; i++){
            const v = board[i][m-1]
            if(v){
                board[i][m-1] = 0;
                return v;
            }
        }
        return 0;
    }
    
    moves.forEach(m => {
        const v = getNumberInBoard(m);
        
        if(v !== 0){
            if(stk.length !== 0 && stk[stk.length -1] === v){
                stk.pop();
                answer += 2;
            }else {
                stk.push(v);
            }    
        }
    })
    return answer;
}