//boj 11048 이동하기
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    int dp[1001][1001] = {0,};
    cin >> n >> m;
    vector<vector<int>> candies(n+1, vector<int>(m+1,0));
    for (int i=1;i<=n;i++){
        vector<int> v(m);
        for (int j=1;j<=m;j++){
            cin >> candies[i][j];
            dp[i][j] = v[j];
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            dp[i][j] = candies[i][j] + max(max(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]);
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
