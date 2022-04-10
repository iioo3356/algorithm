// 프로그래머스 괄호 회전하기
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;

    for (int i=0;i<s.size();i++){    
        stack<char> st;
        if (i>0) {
            string res = s;
            char temp = res[0];
            res.erase(0,1);
            res.push_back(temp);
            s = res;                   
        }
        for (int j=0;j<s.size();j++){
            if (s[j] == '(' || s[j] =='{' || s[j] == '['){
                st.push(s[j]);
            }
            else if (st.top() =='(' && s[j] == ')') st.pop();
            else if (st.top() == '{' && s[j] == '}') st.pop();
            else if (st.top() == '[' && s[j] == ']') st.pop();
            else st.push(s[j]);
        }
        if (st.empty()) answer += 1;
    }
    return answer;
}
