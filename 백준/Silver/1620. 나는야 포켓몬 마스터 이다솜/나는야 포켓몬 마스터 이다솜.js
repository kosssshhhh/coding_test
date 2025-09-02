const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, m] = input[0].split(' ').map(Number);
const pokemons = input.slice(1, n + 1);
const questions = input.slice(n + 1);


function answer(n, m, pokemons, questions) {
    const collection = {};

    pokemons.forEach((p, i) => {
        collection[p] = i + 1;
        collection[i + 1] = p;
    })

    questions.forEach(q => {
        console.log(collection[q]);
    })
}

answer(n, m, pokemons, questions);
