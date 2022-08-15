//boj 10986 나머지 합
#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long arr[10000001];
long long dp[10000001];
long long cnt[10001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    long long s = 0;
    cin >> n >> m;
    // (dp[j]-dp[i])%m=0 -> dp[j]%m - dp[i]%m=0 ->dp[i]%m=dp[j]%m
    // 누적합의 나머지를 모두 구한 후 같은 나머지 조합 개수를 구하면 됨
    for (int i=1;i<=n;i++){
        cin >> arr[i];
        if (i==0) dp[i] = arr[i];
        else dp[i] =(dp[i-1] + arr[i])%m;
        cnt[dp[i]]++;
    }
    s = cnt[0];
    for (int i=0;i<m;i++){
        s += (cnt[i]*(cnt[i]-1))/2;
    }
    cout << s << "\n";
    return 0;
}
