//boj 10162 전자레인지
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    int a_count = 0;
    int b_count = 0;
    int c_count = 0;
    bool isImpossible = false;
    if (t%10 != 0){
        cout << -1 << "\n";
        return 0;
    }

    a_count += t/300;
    t%=300;
    b_count += t/60;
    t%=60;
    c_count += t/10;
    
    cout << a_count << " " << b_count << " " << c_count << "\n";
    return 0;
}
