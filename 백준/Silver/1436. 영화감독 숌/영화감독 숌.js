const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim();
const n = Number(input);

let count = 0;
let num = 666;

while (true) {
    if (String(num).includes("666")) {
        count++;
        if (count === n) {
            console.log(num);
            break;
        }
    }
    num++;
}