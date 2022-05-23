//boj 2475 검증수
#include <iostream>
using namespace std;

int main(){
    int a, b, c, d, e, t;
    cin >> a >> b >> c >> d >> e;
    t = (a*a + b*b + c*c + d*d + e*e)%10;
    cout << t;
    return 0;
}
