//boj 1699 제곱수의 합
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp = {0,1,2,3};
    for (int i=4;i<=n;i++){
        int min_n = i;
        for (int j=2;j*j<=i;j++){
            min_n = min(min_n, dp[i-j*j]+1);
        }
        dp.push_back(min_n);
    }
    cout << dp[n] << endl;
    return 0;
}
