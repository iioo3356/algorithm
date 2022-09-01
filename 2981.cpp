//boj 2981 검문
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    while (b != 0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a, b;  
    int m;
    vector<int> v;
    vector<int> answer;
    for (int i=0;i<n;i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    m = v[1]-v[0];
    for (int i=2;i<n;i++){
        m = gcd(m, v[i]-v[i-1]);
    }
    for (int i=2;i*i<=m;i++){
        if (m%i==0){ 
            answer.push_back(i);
            answer.push_back(m/i);
        }
    }
    answer.push_back(m);
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    for (int i=0;i<answer.size();i++) {
        cout << answer[i] << " ";
    }
    return 0;
}
