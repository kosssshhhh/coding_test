function solution(n)
{
    let answer = 0;
    
    String(n).split('').map(e => answer += +e);

    return answer;
}

// n을 string으로 변환 후, split 메서드를 사용해 배열로 분해한 다음, 각 요소에 대해 다시 int 변환 후 더해준다.