// 프로그래머스 스쿨 문자열 나누기
function solution(s) {
    var answer = 0;
    let currentChar, sameCount = 0, diffCount = 0;
    for (let i=0;i<s.length;i++){      
        if (sameCount === 0){
            currentChar = s[i];
            sameCount++;
        }
        else {
            if (currentChar === s[i]){
                sameCount++;
            }
            else {
                diffCount++;
            }
        }
        if (sameCount === diffCount){
            answer++;
            diffCount = 0;
            sameCount = 0;
        }
    }
    if (sameCount !== 0) answer++;
    return answer;
}
