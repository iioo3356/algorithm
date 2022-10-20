#include <iostream>
using namespace std;

int a[101][101];
int b[101][101];
int c[101][101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    cin >> m >> k;
    for (int i=0;i<m;i++){
        for (int j=0;j<k;j++){
            cin >> b[i][j];
        }
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<k;j++){
            for (int p=0;p<m;p++){
                c[i][j] += a[i][p] * b[p][j];
            }
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
