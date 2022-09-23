//boj 4949 균형잡힌 세상
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true){
        string s;
        getline(cin, s);
        if (s.size() == 1 && s[0] == '.') break;
        stack<char> st;

        for (int i=0;i<s.size();i++){
            if (s[i] == ']'){
                if (!st.empty() && st.top() == '[')
                    st.pop();
                else st.push(s[i]);
            }
            else if (s[i] == ')'){
                if (!st.empty() && st.top() == '(')
                    st.pop();
                else st.push(s[i]);            
            }
            else if (s[i] == '(' || s[i] == '['){
                st.push(s[i]);
            }
        }

        if (st.empty()) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
