// 내 풀이
function solution(food) {
  var answer = '';
  let result1 = [];
  let result2 = [];

  for (let i = 1; i < food.length; i++) {
    for (let j = 0; j < Math.floor(food[i] / 2); j++) {
      result1.push(i);
    }
  }

  result2 = [...result1].reverse();

  answer = result1.join('') + '0' + result2.join('');

  return answer;
}

// 참고 풀이
// function solution(food) {
//   let res = '';

//   for (let i = 1; i < food.length; i++) {
//     res += String(i).repeat(Math.floor(food[i] / 2));
//   }

//   return res + '0' + [...res].reverse().join('');
// }
