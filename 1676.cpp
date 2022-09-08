//boj 1676 팩토리얼 0의 개수
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int count = 0;
    if (n <= 4) cout << count;
    else {
        for (int i=1;i<=n;i++){
            if (i%125 == 0) count += 3;
            else if (i%25 == 0) count += 2; 
            else if (i%5 == 0) count += 1;
        }
        cout << count; 
    }
    return 0;
}
