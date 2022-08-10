// boj 1100 하얀 칸
#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    int ans = 0;
    for (int i=0;i<8;i++){
        cin >> s;
        for (int j=0;j<8;j++){
            if (s[j] == 'F'){
                if (i%2==0  && j%2==0) ans++;
                else if (i%2==1 && j%2==1) ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
