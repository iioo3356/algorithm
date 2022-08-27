//boj 2609 최대공약수와 최소공배수
#include <iostream>
#include <vector>
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
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << "\n";
    cout << (a*b) / gcd(a,b) << "\n";
    return 0;
}
