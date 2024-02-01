// 내 풀이
function solution(t, p) {
  let res = 0;

  for (let i = 0; i <= t.length - p.length; i++) {
    Number(t.substr(i, p.length)) <= p ? res++ : null;
  }

  return res;
}

// 참고 풀이
// 문자열 앞에 + 를 붙이면 숫자로 변환됨
// function solution(t, p) {
//   let count = 0;
//   for (let i = 0; i <= t.length - p.length; i++) {
//     let value = t.slice(i, i + p.length);
//     if (+p >= +value) count++;
//   }
//   return count;
// }
