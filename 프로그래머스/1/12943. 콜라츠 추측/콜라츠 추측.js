function solution(num) {

    const collatz = (num) => {
        for (let i = 1; i<=500; i++){
            if(num % 2 === 0) num /= 2;
            else if(num % 2 === 1) num = num * 3 + 1;
            
            if(num === 1) return i;
        }
        
        return -1;
    }
    
    return num === 1 ? 0 : collatz(num);
}