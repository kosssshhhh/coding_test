const go = (idx, v, target, numbers) => {
    if(idx === numbers.length){
        if(v === target) return 1;
        else return 0;
    }
    
    return go(idx + 1, v + numbers[idx], target, numbers) + go(idx + 1, v - numbers[idx], target, numbers);
}

function solution(numbers, target) {
    return go(0, 0, target, numbers);
}