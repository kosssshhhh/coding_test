function solution(food) {
  var answer = '';
  let result1 = [];
  let result2 = [];

  for (let i = 0; i < food.length; i++) {
    if (i === 0) {
      console.log('i===0');
    } else {
      for (let j = 0; j < Math.floor(food[i] / 2); j++) {
        result1.push(i);
      }
    }
  }

  result2 = [...result1].reverse();

  answer = result1.join('') + '0' + result2.join('');

  return answer;
}