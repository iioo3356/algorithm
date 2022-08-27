//boj 1037 약수
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    long long int ans = 1;
    cin >> num;
    vector<int> v;
    for (int i=0;i<num;i++){
        int n;
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    ans = v[0] * v[v.size()-1];
    cout << ans << endl;
    return 0;
}
