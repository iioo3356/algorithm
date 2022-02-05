// 프로그래머스 3진법 뒤집기
#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int answer = 0;
    string ternary;
    while (n>=3){
        ternary += to_string(n%3);
        n /= 3;
    }
    ternary += to_string(n);
    int y = 1;
    for (int i=ternary.size()-1;i>=0;i--){
        answer += (ternary[i] - int('0')) * y;
        y *= 3;
    }
    return answer;
}
