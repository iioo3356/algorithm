//boj 1992 쿼드트리

#include <iostream>
using namespace std;
int arr[65][65];
string answer = "";

void quadTree(int r1, int r2, int c1, int c2){
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
        answer += to_string(arr[r1][c1]);
        return;
    }
    else {
        answer += "(";
        quadTree(r1, (r1+r2)/2, c1, (c1+c2)/2);
        quadTree(r1, (r1+r2)/2,  (c1+c2)/2, c2);
        quadTree((r1+r2)/2, r2, c1, (c1+c2)/2);
        quadTree((r1+r2)/2, r2, (c1+c2)/2, c2);
        answer += ")";
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        string str;
        cin >> str;
        for (int j=0;j<n;j++){
            string s;
            s = str[j];
            arr[i][j] = stoi(s);
        }
    }

    quadTree(0,n,0,n);
    cout << answer << "\n";
    return 0;
}
