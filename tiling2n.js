// 프로그래머스 2*n 타일링
function solution(n) {
    var answer = 0;
    //dp[n] = 가로 길이가 n일 때 경우의 수
    const dp = [0,1,2];
    for (let i=3;i<=n;i++){
        // 가장 오른쪽에 채울 수 있는 모양이 직사각형의 짧은 면을 아래에 둔 경우(n-1)와
        // 직사각형의 긴 면을 아래에 둔 채로 두 개 겹치게 둔 경우(n-2)의 합을 구하면 됨
        dp.push((dp[i-1]+dp[i-2])%1000000007);
    }
    answer = dp[n];
    return answer;
}
