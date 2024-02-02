// 배열의 indexOf, splice 등을 이용하면 성능이 안나옴
// 따라서 Object에 인덱스를 담아서 사용

function solution(players, callings) {
  let index;
  let player1;
  let player2;
  const obj = {};

  players.forEach((a, i) => {
    obj[a] = i + 1;
  });

  callings.forEach((a, i) => {
    index = obj[a] - 1;

    player1 = players[index];
    player2 = players[index - 1];

    players[index] = player2;
    players[index - 1] = player1;

    obj[player1] = obj[player1] - 1;
    obj[player2] = obj[player2] + 1;
  });

  return players;
}
