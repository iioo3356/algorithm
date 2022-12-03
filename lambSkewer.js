// 프로그래머스 양꼬치
function solution(n, k) {
    var answer = 0;
    let service = Math.floor(n/10);
    answer += 12000 * n;
    answer += 2000 * (k - service);
    return answer;
}
