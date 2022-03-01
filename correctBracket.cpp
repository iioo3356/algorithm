// 프로그래머스 올바른 괄호
#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = false;
    stack<int> st;
    for (int i=0;i<s.size();i++){
        if (st.empty()){
            st.push(s[i]);
        }
        else {
            if (st.top() == '(' && s[i] == ')'){
                st.pop();
            }
            else {
                st.push(s[i]);
            } 
        }
        
    }
    if (st.empty()) answer = true;
    return answer;
}
