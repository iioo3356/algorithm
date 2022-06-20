//boj 11050 이항계수
#include <iostream>
using namespace std;
int factorial(int t) {
    int answer = 1;
    for (int i=t;i>0;i--) {
        answer *= i;
    }
    return answer;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << factorial(n)/(factorial(k)*factorial(n-k));
    return 0;
}
