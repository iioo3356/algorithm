// 프로그래머스 가운데 글자 가져오기
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    if (s.size()%2==0){
        answer += s[s.size()/2-1];
        answer += s[s.size()/2];
    }
    else {
        answer += s[s.size()/2];
    }
    return answer;
}
