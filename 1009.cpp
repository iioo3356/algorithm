//boj 1009 분산처리
#include <iostream>
using namespace std;
int main() {
    int numTestCases;
    cin >> numTestCases;
    for (int test=0;test<numTestCases;test++){
        int a, b;
        int answer = 1;
        cin >> a >> b;
        while (b>0){
            answer *= a;
            answer %= 10;
            b--;
        }
        if (answer == 0) cout << 10 << endl;
        else cout << answer << endl;
    }
    return 0;
}
