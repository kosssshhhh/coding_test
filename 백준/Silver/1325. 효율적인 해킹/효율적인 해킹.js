const fs = require('fs');
const input = fs.readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt')
  .toString().trim().split('\n');

const [n, m] = input[0].split(' ').map(Number);
const adj = Array.from({ length: n + 1 }, () => []);

// 간선은 정확히 m줄만 처리
for (let i = 1; i <= m; i++) {
  const [a, b] = input[i].split(' ').map(Number);
  // B를 해킹하면 A도 해킹 가능 → 역방향 그래프: b -> a
  adj[b].push(a);
}

// 방문 배열을 매번 재할당하지 않고 태깅 방식 사용
const visitedTag = new Int32Array(n + 1);
let tag = 0;

const dfsCount = (start) => {
  tag++;
  let cnt = 0;
  const stack = [start];
  visitedTag[start] = tag;

  while (stack.length) {
    const v = stack.pop();
    cnt++;
    const neis = adj[v];
    for (let i = 0; i < neis.length; i++) {
      const u = neis[i];
      if (visitedTag[u] !== tag) {
        visitedTag[u] = tag;
        stack.push(u);
      }
    }
  }
  return cnt;
};

const counts = new Int32Array(n + 1);
let mx = 0;

for (let i = 1; i <= n; i++) {
  const c = dfsCount(i);
  counts[i] = c;
  if (c > mx) mx = c;
}

const ans = [];
for (let i = 1; i <= n; i++) {
  if (counts[i] === mx) ans.push(i);
}
console.log(ans.join(' '));