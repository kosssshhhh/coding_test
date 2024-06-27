function solution(code) {
    let mode = 0
    let ret = ''
    
   code.split('').forEach((a, idx)=>{
       switch(mode){
            case 0:
                if(a !== '1' && idx % 2 === 0){
                    ret += a
                }
                if(a === '1'){
                    mode = 1
                }
                break;
            case 1:
                if (a !== '1' && idx % 2 === 1){
                    ret += a
                }
                if(a === '1'){
                    mode = 0;
                }
                break;
        }
    
   })
        
    return ret === '' ? 'EMPTY' : ret;
}