//boj 24416 알고리즘 수업 - 피보나치 수 1
#include <iostream>
#include <vector>
using namespace std;

int count_f1;
int count_f2;
int arr[51] = {0,1,1};

int fibo(int n){
    if (n==1 || n==2){ 
        count_f1+=1;
        return 1;
    }
    else return fibo(n-1)+fibo(n-2);
}

int fibonacci(int n){
    for (int i=3;i<=n;i++){
        count_f2+=1;
        arr[i] = arr[i-1]+arr[i-2];
    }
    return arr[n];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    fibo(n);
    fibonacci(n);
    cout << count_f1 << " " << count_f2;
    return 0;
}
