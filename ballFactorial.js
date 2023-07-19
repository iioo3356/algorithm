// 프로그래머스 구슬을 나누는 경우의 수
function factorial(num) {
    if (num <= 1) return num;
    return num * factorial(num-1);
}
function solution(balls, share) {
    if (share === balls) return 1;
    const answer = Math.round(factorial(balls) / (factorial(balls-share) * factorial(share)));
    return answer;
}
