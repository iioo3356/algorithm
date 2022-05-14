#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    vector<int> v;
    cin >> n;
    for (int i=0;i<n;i++){
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    int s = v[0];
    int answer = v[0];
    for (int i=1;i<n;i++){
        s += v[i];
        answer += s;
    }
    cout << answer << endl;
    return 0;
}
