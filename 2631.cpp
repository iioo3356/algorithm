//boj 2631 줄 세우기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, answer = -1;
    cin >> n;
    vector<int> v(n, 0);
    for (int i=0;i<n;i++){
        cin >> v[i];
    }
    // LIS(Longest Increasing Subsequence) 알고리즘 이용
    vector<int> dp(n+1,0); // dp[x] : x번째 수를 마지막 원소로 가지는 부분 수열의 길이
    for (int i=0;i<n;i++){
        if (dp[i] == 0) dp[i] = 1;
        for (int j=0;j<i;j++){
            if (v[i] > v[j]){
                if (dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
        }
        answer = max(answer, dp[i]);
    }
    cout << n - answer;
    return 0;
}
