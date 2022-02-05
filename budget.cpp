// 프로그래머스 예산
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    for (int i=0;i<d.size();i++){
        if (d[i]<=budget){
            budget -= d[i];
            answer += 1;
        }
    }
    return answer;
}
