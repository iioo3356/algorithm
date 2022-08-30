//boj 1934 최소공배수
#include <iostream>
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
    int numTestCases;
    cin >> numTestCases;
    for (int t=0;t<numTestCases;t++){
        int a, b;
        cin >> a >> b;
        cout << (a*b) / gcd(a,b) << "\n";
    }
    return 0;
}
