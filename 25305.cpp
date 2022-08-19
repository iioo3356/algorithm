//boj 25305 커트라인
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    cout << v[k-1] << endl;
    return 0;
}
