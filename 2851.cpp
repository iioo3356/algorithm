//boj 2851 슈퍼마리오
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return 100-a<100-b;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> v(10);
    for (int i=0;i<10;i++){
        cin >> v[i];
    }
    int sum = 0;
    for (int i=0;i<10;i++){
        if (abs(100-sum)>=abs(100-(sum+v[i]))) sum += v[i];
        else break;
    }
    cout << sum << endl;
    return 0;
}
