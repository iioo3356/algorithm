//boj 2669 직사각형 네개의 합집합의 면적 구하기
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int answer = 0;
    int arr[4][4];
    int m[101][101] = {0,};
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            cin >> arr[i][j];
        }
    }
    for (int i=0;i<4;i++){
        for (int c=arr[i][0];c<arr[i][2];c++){
            for (int r=arr[i][1];r<arr[i][3];r++){
                if (m[r][c] == 0) m[r][c] = 1;
            }
        }
    }
    for (int i=0;i<101;i++){
        for (int j=0;j<101;j++){
            if (m[i][j] == 1) answer++;
        }
    }
    cout << answer << endl;
    return 0;
}
