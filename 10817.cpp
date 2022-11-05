//boj 10817 세 수
#include <iostream>
using namespace std;

int arr[101];

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    arr[a] += 1;
    arr[b] += 1;
    arr[c] += 1;

    int count = 0;
    int center = -1;
    for (int i=0;i<101;i++){
        if (arr[i] > 0) {
            count += arr[i];
            if (count >= 2){
                center = i;
                break;
            }
        }
    }

    cout << center << "\n";
    return 0;
}
