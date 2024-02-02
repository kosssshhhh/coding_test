function solution(players, callings) {
  const obj = {};

  players.forEach((a, i) => {
    obj[a] = i + 1;
  });

  callings.forEach((a, i) => {
    let index = obj[a] - 1;

    let player1 = players[index];
    let player2 = players[index - 1];

    players[index] = player2;
    players[index - 1] = player1;

    obj[player1] = obj[player1] - 1;
    obj[player2] = obj[player2] + 1;
  });

  return players;
}