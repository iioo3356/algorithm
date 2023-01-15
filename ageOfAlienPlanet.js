// 프로그래머스 스쿨 외계행성의 나이
function solution(age) {
    var answer = '';
    const ageStr = age.toString();
    for (let i=0;i<ageStr.length;i++){
        answer += String.fromCharCode("a".charCodeAt(0)+Number(ageStr[i]));
    }
    return answer;
}
