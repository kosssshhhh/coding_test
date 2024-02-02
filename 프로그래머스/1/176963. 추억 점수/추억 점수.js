function solution(name, yearning, photo) {
  const obj = {};
  const result = [];
  let sum = 0;

  for (let i = 0; i < name.length; i++) {
    obj[name[i]] = yearning[i];
  }

  photo.forEach((array, _) => {
    sum = 0;

    array.forEach((a, i) => {
      if (obj[a]) {
        sum += obj[a];
      }
    });
    result.push(sum);
  });

  return result;
}