const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

rl.on('line', function (line) {
  input = [line];
}).on('close', function () {
  str = input[0].split('');
  let result = [];

  str.forEach((element, index) => {
    if (element === element.toUpperCase()) {
      result.push(element.toLowerCase());
    } else {
      result.push(element.toUpperCase());
    }
  });

  console.log(result.join(''));
});
