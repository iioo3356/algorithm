//boj 2845 파티가 끝나고 난 뒤
#include <iostream>
using namespace std;
int main() {
    int L, P;
    cin >> L >> P;
    for (int i=0;i<5;i++){
        int n;
        cin >> n;
        cout << n - L*P << " ";
    }
    return 0;
}
