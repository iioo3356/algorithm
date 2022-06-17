//boj 10039 평균점수
#include <iostream>
using namespace std;

int main() {
    int sumN = 0;
    for (int i=0;i<5;i++){
        int n;
        cin >> n;
        if (n <= 40) sumN+=40;
        else sumN += n;
    }
    cout << sumN/5 << endl;
}
