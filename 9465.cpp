//boj 9465 스티커
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t, n;
    cin >> t;
    for (int test=0;test<t;test++){
        cin >> n;
        int max_score = -1;
        vector<vector<int>> s(2, vector<int>(n,0));
        int dp[2][n]; // dp[i][j] i행에서 j열까지의 최대값
        for (int i=0;i<2*n;i++){
            if (i<n) cin >> s[0][i];
            else cin >> s[1][i%n];
        }
        dp[0][0] = s[0][0];
        dp[1][0] = s[1][0];
        dp[0][1] = s[0][1] + dp[1][0]; // 대각선 최대값 + 현재 위치
        dp[1][1] = s[1][1] + dp[0][0];
        for (int i=2;i<n;i++) { 
            dp[0][i] = max(max(dp[1][i-1], dp[1][i-2]), dp[0][i-2]) + s[0][i];
            dp[1][i] = max(max(dp[0][i-1], dp[0][i-2]),dp[1][i-2]) + s[1][i];
        }
        cout << max(dp[0][n-1], dp[1][n-1]) << endl;
    }
    return 0;
}
