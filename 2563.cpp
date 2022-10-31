// boj 2563 색종이
#include <iostream>
using namespace std;

int arr[101][101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        int c, r;
        cin >> c >> r;
        for (int j=r;j<r+10;j++){
            for (int k=c;k<c+10;k++){
                if (arr[j][k] != 1){
                    arr[j][k] = 1;
                }
            }
        }
    }
    int answer = 0;
    for (int i=0;i<100;i++){
        for (int j=0;j<100;j++){
            if (arr[i][j] == 1) answer += 1;
        }
    }
    cout << answer << "\n";
    return 0;
}
