function solution(cards1, cards2, goal) {
    let idx1 = 0;
    let idx2 = 0;
    
    for (let i = 0; i < goal.length; i++) {
        if (idx1 < cards1.length && cards1[idx1] === goal[i]) {
            idx1++;
        } else if (idx2 < cards2.length && cards2[idx2] === goal[i]) {
            idx2++;
        } else {
            return 'No';
        }
    }
    
    return 'Yes';
}