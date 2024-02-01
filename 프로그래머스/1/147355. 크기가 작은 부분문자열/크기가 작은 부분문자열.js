function solution(t, p) {
  let res = 0;

  for (let i = 0; i <= t.length - p.length; i++) {
    Number(t.substr(i, p.length)) <= p ? res++ : null;
  }

  return res;
}
