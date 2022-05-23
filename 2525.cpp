// boj 2525 오븐시계
#include <iostream>
using namespace std;

int main(){
    int h, m, c;
    cin >> h >> m >> c;
    m += c;
    if (m > 59) {
        h += m/60;
        m = m%60;
    }
    if (h > 23) {
        h = h%24;
    }
    cout << h <<" " << m;
    return 0;
}
