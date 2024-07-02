function solution(s, skip, index) {
    let answer = '';

    for (let i = 0; i < s.length; i++) {
        let currentChar = s[i];
        let shifts = 0;

        while (shifts < index) {
            currentChar = String.fromCharCode(currentChar.charCodeAt(0) + 1);

            // 'z'를 넘어가면 'a'로 다시 시작
            if (currentChar > 'z') {
                currentChar = 'a';
            }

            // skip에 포함되지 않는 문자만 유효한 이동으로 간주
            if (!skip.includes(currentChar)) {
                shifts++;
            }
        }

        answer += currentChar;
    }

    return answer;
}

