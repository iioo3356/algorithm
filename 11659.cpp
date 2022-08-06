//boj 11659 구간 합 구하기 4
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v;
    for (int i=0;i<n;i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    for (int i=0;i<m;i++){
        int ii, jj;
        int s = 0;
        cin >> ii >> jj;
        for (int j=ii-1;j<jj;j++){
            s += v[j];
        }
        cout << s << "\n";
    }
    return 0;
}
