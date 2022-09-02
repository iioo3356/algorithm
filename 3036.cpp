//boj 3036 링
#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
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
    vector<int> v;
    for (int i=0;i<n;i++){
        int r;
        cin >> r;
        v.push_back(r);
    }
    for (int i=1;i<n;i++){
        int g = gcd(v[i], v[0]);
        cout << v[0]/g << "/" << v[i]/g << "\n";
    }
    return 0;
}
