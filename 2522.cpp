//boj 2522 별찍기 - 12
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i=0;i<2*n-1;i++){
        if (i==n-1){
            for (int j=0;j<n;j++) cout << "*";
        }
        else if (i<n-1){
            for (int j=0;j<n-i-1;j++) cout << " ";
            for (int j=0;j<=i;j++) cout << "*";
        }
        else {
            for (int j=0;j<i+1-n;j++) cout << " ";
            for (int j=0;j<2*n-i-1;j++) cout << "*";
        }
        cout << "\n";
    }
    return 0;
}
