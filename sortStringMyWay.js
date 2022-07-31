// 프로그래머스 문자열 내 마음대로 정
function solution(strings, n) {
    var answer = strings.sort(function (a, b) {
        if (a[n] === b[n]) {
            return (a > b)?1:-1
        }
        else if (a[n] > b[n]) return 1;
        else return -1;
    })
    return answer;
}
