//boj 12865 평범한 배낭
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int dp[101][100001];

bool cmp(pair<int,int> a, pair<int,int> b){
    if (a.second == b.second ) return a.first < b.first;
    return a.second > b.second;
}

int main(){
    int n, k, w, v;
    vector<pair<int,int>> items;
    cin >> n >> k;
    for (int i=0;i<n;i++){
        cin >> w >> v;
        items.push_back(make_pair(w, v));
    } 
    for(int i=1;i<=n;i++){
        int weight = items[i-1].first;
        int value=items[i-1].second;
        for(int j=0;j<=k;j++){
            if (j < items[i-1].first) dp[i][j]=dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight]+value);
        }
    } 
    cout << dp[n][k];
    return 0;
}
