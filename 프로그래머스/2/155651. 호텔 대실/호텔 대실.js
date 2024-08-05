function solution(book_time) {
    let answer = 0;
    let rooms = [];
    
    book_time.forEach((a, i)=>{
        let [startHour, startMin] = a[0].split(':'); 
        a[0] = parseInt(startHour) * 60 + parseInt(startMin);
        
        let [endHour, endMin] = a[1].split(':');
        a[1] = parseInt(endHour) * 60 + parseInt(endMin) + 10;
    })
    
    book_time.sort((a,b) => a[0] - b[0])
    
    book_time.forEach((a)=>{
        const idx = rooms.findIndex((e) => e <= a[0]);
        
        if(idx === -1) rooms.push(a[1]);
        else rooms[idx] = a[1];
    })
    console.log(rooms)
    
    return rooms.length;
}