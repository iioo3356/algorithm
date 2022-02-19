// 프로그래머스 멀쩡한 사각형
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    
    for (int i=1;i<w+1;i++){
        answer += floor((unsigned long long)h*(i-1)/(double)w) - ceil((unsigned long long)h*i/(double)w);

    }
    answer += (unsigned long long)w*h;
    return answer;
}
