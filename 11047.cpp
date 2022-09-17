//boj 11047 동전 0
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    long long k;
    int answer = 0;
    cin >> n >> k;
    vector<long long> v(n+1);
    for (int i=0;i<n;i++){
        cin >> v[i];
    }
    while (k>0){
        if (v[n]>0) {
            answer += k/v[n];
            k %= v[n];
        }
        n-=1;
    }
    cout << answer;
    return 0;
}
