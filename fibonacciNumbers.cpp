// 프로그래머스 피보나치 수
#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<long long int> fibo;
    fibo.push_back(0);
    fibo.push_back(1);
    for (int i=2;i<n+1;i++){
        fibo.push_back((fibo[i-2]+fibo[i-1])%1234567);
    }
    answer = fibo[n];
    return answer;
}
