// 프로그래머스 짝지어 제거하기
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> st;
    st.push(s[0]);
    for (int i=1;i<s.size();i++){
        if (st.empty()) st.push(s[i]);
        else if (st.top() == s[i]){
            st.pop();
        }
        else {
            st.push(s[i]);
        }
    }
    if (st.size() == 0) return 1;
    else return 0;
}
