// boj 11052 카드 구매하기
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, p;
    vector<long long> packs = {0,};
    vector<long long> dp = {0,};
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> p;
        packs.push_back(p);
    }
    dp.push_back(packs[1]);
    for (int i=2;i<=n;i++){
        long long max_n = packs[i];
        for (int j=1;j<i;j++){
            max_n = max(max_n, dp[j] + dp[i-j]);
        }
        dp.push_back(max_n);
    }
    cout << dp[n] << endl;
    return 0;
}
