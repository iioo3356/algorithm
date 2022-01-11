// 프로그래머스 없는 숫자 더하기
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    int numArr[] = {1,1,1,1,1,1,1,1,1,1};
    for (int i=0;i<numbers.size();i++){
        if(numArr[numbers[i]] > 0){
            numArr[numbers[i]] -= 1;
        }
    }
    for (int i=0;i<10;i++){
        if (numArr[i] == 1){
            answer += i;
        }
    }
    cout << endl;
    return answer;
}

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
