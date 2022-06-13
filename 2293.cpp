//boj 2293 동전1
#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n, k;
    cin >> n >> k;
    vector<int> coins;
    vector<int> dp(k+1,0);
    for (int i=0;i<n;i++){
        int t;
        cin >> t;
        coins.push_back(t);
    }
    dp[0] = 1;
    for (int i=0;i<n;i++){
        for (int j=coins[i];j<=k;j++){
            dp[j] += dp[j-coins[i]];
        }
    }
    cout << dp[k] << endl;
    return 0;
}
