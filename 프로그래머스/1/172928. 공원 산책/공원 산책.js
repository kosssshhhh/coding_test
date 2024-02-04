function solution(park, routes) {
  let answer = [];
  let my_routes = [];

  for (let i = 0; i < park.length; i++) {
    park[i] = park[i].split('');
  }

  for (let i = 0; i < routes.length; i++) {
    routes[i] = routes[i].split(' ');
  }

  // 시작 점 찾기
  for (let i = 0; i < park.length; i++) {
    for (let j = 0; j < park[i].length; j++) {
      if (park[i][j] === 'S') {
        my_routes.push(j);
        my_routes.push(i);
        park[i][j] = 'O';
      }
    }
  }

  for (let i = 0; i < routes.length; i++) {
    let route = [...my_routes];

    for (let j = 0; j < Number(routes[i][1]); j++) {
      if (routes[i][0] === 'E') {
        //오른쪽
        if (
          route[0] + 1 < 0 ||
          route[0] + 1 > park[0].length - 1 ||
          park[route[1]][route[0] + 1] === 'X'
        ) {
          route = [...my_routes];
          break;
        } else {
          route[0]++;
        }
      } else if (routes[i][0] === 'S') {
        //아래
        if (
          route[1] + 1 < 0 ||
          route[1] + 1 > park.length - 1 ||
          park[route[1] + 1][route[0]] === 'X'
        ) {
          route = [...my_routes];
          break;
        } else {
          route[1]++;
        }
      } else if (routes[i][0] === 'W') {
        //왼쪽
        if (
          route[0] - 1 < 0 ||
          route[0] - 1 > park[0].length - 1 ||
          park[route[1]][route[0] - 1] === 'X'
        ) {
          route = [...my_routes];
          break;
        } else {
          route[0]--;
        }
      } else if (routes[i][0] === 'N') {
        //위
        if (
          route[1] - 1 < 0 ||
          route[1] - 1 > park.length - 1 ||
          park[route[1] - 1][route[0]] === 'X'
        ) {
          route = [...my_routes];
          break;
        } else {
          route[1]--;
        }
      }
    }
    my_routes = [...route];
  }

  answer = [my_routes[1], my_routes[0]];

  return answer;
}