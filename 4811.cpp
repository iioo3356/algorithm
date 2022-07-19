//boj 4811 알약
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long dp[31][31] = {0,}; // dp[i][j] : 완전한 알약이 i개 있고 반절 알약이 j개
    for (int i=1;i<31;i++){
        dp[0][i] = 1; // 반절 알약만 있는 경우 hhh.... 의 한가지 경우만 존재
    }
    dp[1][0] = 1; //완전 알약 1개 -> wh
    for (int i=1;i<31;i++){
        for (int j=0;j<31;j++){
            dp[i][j] = dp[i-1][j+1]; // 완전 알약을 꺼내는 경우 반절 알약을 새로 추가
            if (j>0) dp[i][j] += dp[i][j-1]; // 반절 알약을 꺼내는 경우 완전 알약 개수에 변화 없음
        }
    }
    while (true) {
        int n;
        cin >> n;
        if (n==0) break;
        cout << dp[n][0] << endl;
    }
    return 0;
}
