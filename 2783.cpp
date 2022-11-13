// boj 2783 행렬 덧셈
#include <iostream>

using namespace std;

int A[101][101];
int C[101][101];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;

    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> A[i][j];
        }
    }
    
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            int bNum;
            cin >> bNum;
            C[i][j] = A[i][j] + bNum;
        }
    }

    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
