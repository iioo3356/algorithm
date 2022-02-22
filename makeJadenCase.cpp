// 프로그래머스 JadenCase 문자열 만들기
#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    string answer = "";
    bool isFirst = true;
    for (int i=0;i<s.size();i++){
        if (isFirst){
            if (s[i] == ' '){
                answer += s[i];
                continue;
            }
            if (s[i]>='a' && s[i]<='z'){
                answer += s[i] - 32;
            }
            else {
                answer += s[i];
            }
            isFirst = false;
        }
        else {
            if (s[i]>='A' && s[i] <= 'Z'){
                answer += s[i] + 32;
                continue;
            }
            else if (s[i] == ' '){
                isFirst = true;
            }
            answer += s[i];
        }
    }
    return answer;
}
