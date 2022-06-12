#include <iostream>
#include <vector>

using namespace std;

int main() {
    string a;
    string b;
    cin >> a >> b;
    vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1,0));
    //dp[i][j] a의 i번째 글자까지, b의 j번째 글자까지 봤을 때 최대 lcs 길이
    for (int i=1;i<=a.size();i++){
        for (int j=1;j<=b.size();j++){
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1; //이전 부분의 lcs 길이 + 1
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[a.size()][b.size()] << endl;
    return 0;
}
