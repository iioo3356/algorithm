#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;

    for (int i=0;i<s.size();i++){    
        string res = s;
        char temp = res[0];
        res.erase(0,1);
        res.push_back(temp);
        s = res;                   
        stack<string> st;
        for (int j=0;j<s[i].size();j++){
            if (s[i][j] == '(' || s[i][j] =='{' || s[i][j] == '['){
                st.push(str[i]);
            }
            else if (st.top() =='(' && s[i][j] == ')') st.pop();
            else if (st.top() == '{' && s[i][j] == '}') st.pop();
            else if (st.top() == '[' && s[i][j] == ']') st.pop();
        }
          if (st.empty()) answer += 1;                       
    }
    return answer;
}
