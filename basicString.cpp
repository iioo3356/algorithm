// 문자열 다루기 기본

#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if (s.size() == 4 || s.size() == 6){
        for (int i=0;i<s.size();i++){
            if (('a'<=s[i] && s[i]<='z')|| ('A'<=s[i] && s[i]<='Z')){
                answer = false;
                break;
            }
        }
    }
    else answer = false;
    return answer;
}
