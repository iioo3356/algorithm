// 프로그래머스 멀리 뛰기
function solution(n) {
    var answer = 0;
    let dp = [0,1,2] // dp[n] = n번째 칸을 뛰는 경우의 수
    // n 번째 칸을 뛰는 경우의 수 = 효진이가 마지막에 한 칸을 뛰는 경우 + 마지막에 두 칸을 뛰는 경우
    // 마지막에 한 칸을 뛰는 경우 = 남은 칸의 개수 n - 1
    // 마지막에 두 칸을 뛰는 경우 = 남은 칸의 개수 n - 2
    for (let i=3;i<=n;i++){
        dp.push((dp[i-1]+dp[i-2])%1234567);
    }
    answer = dp[n];
    return answer;
}
