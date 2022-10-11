//boj 1780 종이의 개수

#include <iostream>
using namespace std;
int arr[3001][3001];
int answer_0, answer_1, answer_m_1;

void func(int r1, int r2, int c1, int c2){
    bool isSame = true;
    for (int i=r1;i<r2;i++){
        for (int j=c1;j<c2;j++){
            if (arr[i][j] != arr[r1][c1]){
                isSame = false;
                break;
            }
        }
    }
    if (isSame == true){
        if (arr[r1][c1] == 1) answer_1++;
        else if (arr[r1][c1] == 0) answer_0++;
        else answer_m_1++;
        return;
    }
    else {
        func(r1, r1+(r2-r1)/3, c1, c1+(c2-c1)/3);
        func(r1, r1+(r2-r1)/3, c1+(c2-c1)/3, c1+2*(c2-c1)/3);
        func(r1, r1+(r2-r1)/3, c1+2*(c2-c1)/3, c2);

        func(r1+(r2-r1)/3, r1+2*(r2-r1)/3, c1, c1+(c2-c1)/3);
        func(r1+(r2-r1)/3, r1+2*(r2-r1)/3, c1+(c2-c1)/3, c1+2*(c2-c1)/3);
        func(r1+(r2-r1)/3, r1+2*(r2-r1)/3, c1+2*(c2-c1)/3, c2);

        func(r1+2*(r2-r1)/3, r2, c1, c1+(c2-c1)/3);
        func(r1+2*(r2-r1)/3, r2, c1+(c2-c1)/3, c1+2*(c2-c1)/3);
        func(r1+2*(r2-r1)/3, r2, c1+2*(c2-c1)/3, c2);

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    func(0,n,0,n);
    cout << answer_m_1 << "\n";
    cout << answer_0 << "\n";
    cout << answer_1 << "\n";
    return 0;
}
