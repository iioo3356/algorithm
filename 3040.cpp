//boj 3040 백설 공주와 일곱 난쟁이
#include <iostream>
using namespace std;

int main() {
    int count = 0;
    int idx1, idx2;
    int arr[9] = {0,};
    for (int i=0;i<9;i++){
        cin >> arr[i];
        count += arr[i];
    }
    for (int i=0;i<8;i++){
        for (int j=i+1;j<9;j++){
            if (arr[i]+arr[j] == count-100){
                idx1= i;
                idx2 = j;
                break;
            }
        }
    }
    for (int i=0;i<9;i++){
        if (i != idx1 && i!= idx2){
            cout << arr[i] << "\n";
        }
    }
}
