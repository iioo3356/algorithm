//boj 25304 영수증
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long x, n;
    cin >> x >> n;
    for (int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        x -= a * b;
    }    
    if (x == 0) cout << "Yes";
    else cout << "No";
    return 0;
}
