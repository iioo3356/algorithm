// 프로그래머스 괄호 변환
#include <string>
#include <vector>
#include <stack>
using namespace std;
string properString(string p, int left, int right){
    if (right == left || right > p.size()){
        return "";
    }
    string answer = "";
    string u = p.substr(left, right-left);
    string v = p.substr(right, p.size()-right);
    stack<char> s;
    int left_bracket = 0;
    int right_bracket = 0;
    for (int i=0;i<u.size();i++){
        if (s.empty()) s.push(u[i]);
        else {
            if (u[i] == '(') {
                s.push(u[i]);
            }
            else if (s.top() == '(') s.pop();
        }
        if (u[i] == '(') {
            left_bracket++;
        }
        else {
            right_bracket++;
        }
    }
    if (left_bracket != right_bracket){
        // u가 균형잡힌 문자열이 아님
        return properString(p, left, right+1);
    }
    else {
        if (s.empty()) {
            // u가 균형잡힌 문자열이고 올바른 괄호 문자열
            answer = u;
            return answer + properString(p, right, right+1);
        }
        else {
            // u가 균형잡힌 문자열이지만 올바른 괄호 문자열이 아님
            answer += "(";
            answer +=  properString(p, right, right+1);
            answer += ")";
            string reverse = u.substr(1, u.size()-2);
            for (int i=0;i<reverse.size();i++){
                if (reverse[i] == '(') reverse[i] = ')';
                else reverse[i] = '(';
            }
            answer += reverse;
            return answer;
        }
    }
}
string solution(string p) {
    string answer = "";
    if (p == "") return "";
    answer = properString(p, 0, 1);
    return answer;
}
