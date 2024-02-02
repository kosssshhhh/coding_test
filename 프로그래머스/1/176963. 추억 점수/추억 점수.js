function solution(name, yearning, photo) {
  const obj = {};
  const result = [];
  let sum = 0;

  name.forEach((a, i) => (obj[a] = yearning[i]));

  photo.forEach((array, _) => {
    sum = 0;
    array.forEach((a) => (obj[a] ? (sum += obj[a]) : 0));
    result.push(sum);
  });

  return result;
}