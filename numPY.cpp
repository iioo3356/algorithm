// 프로그래머스 문자열 내 p와 y의 개수
#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int pNum = 0;
    int yNum = 0;
    for (int i=0;i<s.size();i++){
        if (s[i]=='p' || s[i] == 'P') pNum +=1;
        else if (s[i]=='y' || s[i]=='Y') yNum += 1;
    }
    if (pNum != yNum) answer = false;

    return answer;
}
