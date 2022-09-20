//boj 13305 주유소
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    long long answer = 0;
    vector<long long> price(n);
    vector<long long> dist(n-1);
    for (int i=0;i<n-1;i++){
        cin >> dist[i];
    }
    for (int i=0;i<n;i++){
        cin >> price[i];
    }
    long long minNum = 1000000000;
    for (int i=0;i<n-1;i++){
        if (price[i] < minNum) minNum = price[i];
        answer += minNum * dist[i];
    }
    cout << answer;
    return 0;
}
