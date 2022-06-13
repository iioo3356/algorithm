//boj 11057 오르막수
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int sum = 0;
    cin >> n;
    vector<vector<int>> dp(n+1, vector<int> (10,0));
    for (int i=0;i<10;i++){
        dp[1][i] = 1;
    }
    for (int i=2;i<=n;i++){
        for (int j=0;j<10;j++){
            for (int k=j;k<10;k++){
                dp[i][k] += dp[i-1][j];
                dp[i][k] %= 10007;
            }
        }
    }
    for (int i=0;i<10;i++){
        sum += dp[n][i];
    }
    cout << sum %10007 << endl;
    return 0;
}
