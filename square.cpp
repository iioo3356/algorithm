// 프로그래머스 직사각형 별찍기
#include <iostream>
using namespace std;

int main(void) {
    int m;
    int n;
    cin >> n >> m;
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cout << '*';
        }
        cout << endl;
    }
    return 0;
}
