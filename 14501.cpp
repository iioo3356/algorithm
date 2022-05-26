// boj 14501 퇴사
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, t, p;
    cin >> n;
    vector<int> dp(18,0);
    vector<pair<int,int>> v;
    v.push_back(make_pair(0,0));
    for (int i=0;i<n;i++){
        cin >> t >> p;
        v.push_back(make_pair(t, p));
    }
    int d;
    for (int i=n;i>0;i--){
        if (v[i].first > n-i+1){
            dp[i] = dp[i+1];
        }
        else {
            dp[i] = max(dp[i+1], dp[i+v[i].first]+v[i].second);
        }
    }
    cout << dp[1] << endl;
    return 0;
}
