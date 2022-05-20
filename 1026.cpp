#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> a;
    vector<int> b;
    int n;
    int sum = 0;
    cin >> n;
    for (int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    for (int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
    }
    sort(a.begin(),a.end());
    sort(b.begin(), b.end(), greater<int>());
    for (int i=0;i<n;i++){
        sum += a[i]*b[i];
    }
    cout << sum << endl;
    return 0;
}
