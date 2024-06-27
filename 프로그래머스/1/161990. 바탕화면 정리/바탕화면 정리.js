function solution(wallpaper) {
  let answer = [];
  let [lux, luy] = [wallpaper.length, wallpaper[0].length];
  let [rdx, rdy] = [1, 1];


  wallpaper.forEach((a, i) => {
    a.split('').forEach((b, j)=>{
        if(b === '#'){
            lux = Math.min(lux, i)
            luy = Math.min(luy, j)
            rdx = Math.max(rdx, i+1)
            rdy = Math.max(rdy, j+1)
        }

    })
  });
    
    answer = [lux, luy, rdx, rdy]

  return answer;
}
