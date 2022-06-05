//boj 9095 1,2,3 더하기

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    vector<int> v = {0,1,2,4};
    for (int i=4;i<=11;i++){
        v.push_back(v[i-1] + v[i-2] + v[i-3]);
    }
    for (int test=0;test<t;test++){
        cin >> n;
        cout << v[n] << endl;
    }
    return 0;
}
