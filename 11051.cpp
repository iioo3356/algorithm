//boj 11051 이항 계수 2
#include <iostream>
#include <vector>
using namespace std;

int memo[1001][1001];

int bino(int n, int k) {
    if (n==k) return 1;
    if (k==0) return 1;
    if (memo[n][k] != 0) return memo[n][k];
    return memo[n][k] = bino(n-1, k-1)%10007 + bino(n-1, k)%10007;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    cout << bino(n,k)%10007;
    return 0;
}
