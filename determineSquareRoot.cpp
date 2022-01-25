// 프로그래머스 정수 제곱근 판별
#include <string>
#include <vector>
using namespace std;

long long solution(long long n) {
    unsigned long long answer = 0;
    for (long long i=0;i<=n;i++){
        if (i*i == n){
            answer = (i+1)*(i+1);
            break;
        }
        else {
            answer = -1;
        }
    }
    return answer;
}
