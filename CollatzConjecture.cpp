// 프로그래머스 콜라츠 추측
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num) {
    int answer = 0;
    unsigned long long int modifiedNum = num;
    while (modifiedNum > 1){
        if (answer == 500){
            break;
        }
        answer += 1;
        if (modifiedNum %2 == 0){
            modifiedNum /= 2;
        }
        else {
            modifiedNum *= 3;
            modifiedNum += 1;
        }
    }
    if (answer == 500 && modifiedNum != 1){
        answer = -1;
    }
    return answer;
}
