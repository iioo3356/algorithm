// boj 2630 색종이 만들기
#include <iostream>

using namespace std;

int n, b_count, w_count;
int square[129][129];

void cut(int r1, int r2, int c1, int c2){
    int s = 0;
    if (r1==r2 && c1==c2){
        if (square[r1][c2] == 0) w_count++;
        else b_count++;
        return;
    }
    for (int i=r1;i<r2;i++){
        for (int j=c1;j<c2;j++){
            s+=square[i][j];
        }
    }
    if (s == 0) {
        w_count++;
        return;
    }
    else if (s == (r2-r1)*(c2-c1)){
        b_count++;
        return;
    }
    else {
        cut(r1, r1+(r2-r1)/2, c1, c1+(c2-c1)/2);
        cut(r1+(r2-r1)/2, r2, c1, c1+(c2-c1)/2);
        cut(r1, r1+(r2-r1)/2, c1+(c2-c1)/2, c2);
        cut(r1+(r2-r1)/2, r2, c1+(c2-c1)/2, c2);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> square[i][j];
        }
    }
    cut(0, n, 0, n);
    cout << w_count << "\n" << b_count<< "\n";
    return 0;
}
