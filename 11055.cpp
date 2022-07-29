//boj 11055 가장 큰 증가 부분 수열
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a;
    cin >> a;
    vector<int> v(a);
    vector<int> dp(a);
    for (int i=0;i<a;i++){
        cin >> v[i];
    }
    int answer = 0;
    for (int i=0;i<a;i++){
        dp[i] = v[i];
        for (int j=0;j<i;j++){
            if (v[i]>v[j]) dp[i] = max(dp[i], dp[j]+v[i]);
        }
        answer = max(answer, dp[i]);
    }
    cout << answer << endl;
    return 0;
}
