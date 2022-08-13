//boj 16139 인간-컴퓨터 상호작용
#include <iostream>
#include <string>
using namespace std;

int dp[222222][26];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    char c;
    int q, l, r;
    cin >> s >> q;
    for (int i=0;i<s.size();i++){
        if (i > 0)
            for (int j=0;j<26;j++){
                dp[i][j] = dp[i-1][j];
            }
        dp[i][s[i]-'a'] += 1;
    }
    for (int i=0;i<q;i++){
        cin >> c >> l >> r;
        if (l>0) cout << dp[r][c-'a'] - dp[l-1][c-'a'] << "\n";
        else cout << dp[r][c-'a'] << "\n";
    }
    return 0;
}
