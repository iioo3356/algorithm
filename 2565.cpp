//boj 2565 전깃줄
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    for (int i=0;i<n;i++){
        int n1, n2;
        cin >> n1 >> n2;
        v.push_back(make_pair(n1,n2));
    }
    // 교차하지 않도록 : A 전봇대 오름차순일 때 B 전봇대로 가는 전깃줄도 오름차순이어야함.
    sort(v.begin(), v.end());
    // LIS 의 길이를 n에서 빼서 오름차순을 방해하는 전깃줄의 개수를 구함
    int lis_l = -1;
    vector<int> dp(n+1,0); // dp[x] : x번째 수를 마지막 원소로 가지는 부분 수열의 길이
    for (int i=0;i<n;i++){
        if (dp[i] == 0) dp[i] = 1;
        for (int j=0;j<i;j++){ 
            if (v[i].second > v[j].second){
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
        lis_l = max(lis_l, dp[i]);
    }
    cout << n - lis_l << endl;
    return 0;
}
