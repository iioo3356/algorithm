//boj 11659 구간 합 구하기 4
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v;
    vector<int> dp = {0,};
    for (int i=1;i<=n;i++){
        int num;
        cin >> num;
        v.push_back(num);
        dp.push_back(dp[i-1]+num);
    }
    for (int i=0;i<m;i++){
        int ii, jj;
        cin >> ii >> jj;
        cout << dp[jj] - dp[ii-1] << "\n";
    }
    return 0;
}
