// 프로그래머스 이상한 문자 만들기
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string solution(string s) {
    string answer = "";
    int index = 0;
    for (int i=0;i<s.size();i++){
        if (s[i] == ' ') {
            index = -1;
            answer += ' ';
        }
        else if (index % 2 == 0) 
            answer += (char)toupper(s[i]);
        else 
            answer += (char)tolower(s[i]);
        index++;
    }
    return answer;
}
