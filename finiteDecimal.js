// 프로그래머스 유한소수 판별하기
function solution(a, b) {
    var answer = 0;
    answer = a/b === Number((a/b).toFixed(10)) ? 1:2;
    return answer;
}
