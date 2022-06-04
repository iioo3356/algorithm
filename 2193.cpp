// boj 2193 이친소
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    vector<long long> dp = {0,1,1};
    cin >> n;
    for (int i=3;i<=n;i++){
        dp.push_back(dp[i-1] + dp[i-2]);
    }
    cout << dp[n] << endl;
    return 0;

}
