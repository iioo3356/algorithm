// boj 1629 곱셈
#include <iostream>
#include <cmath>
using namespace std;

int a, b, c;
int power(int num, int count){
    if (count==0) return 1;
    int tmp = power(num, count/2);
    
    if (count %2==0)
        return 1LL * tmp * tmp %c;
    else 
        return ((1LL * tmp * tmp)%c) * num % c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;
    int answer = power(a, b)%c;
    cout << answer << "\n";
    return 0;
}
