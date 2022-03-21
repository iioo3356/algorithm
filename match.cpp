// 프로그래머스 예상대진표
#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    while (!((a%2==1 && b == a+1) || (b%2==1 && a == b+1))){
          a = a - a/2;
            b = b - b/2;
        answer += 1;
    }
    return answer;
}
