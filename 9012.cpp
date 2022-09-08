//boj 9012 괄호
#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int numTestCases;
    cin >> numTestCases;
    for (int t=0;t<numTestCases;t++){
        stack<char> st;
        string s;
        cin >> s;
        for (int i=0;i<s.size();i++){
            if (st.empty()) st.push(s[i]);
            else {
                if (st.top() == '(' && s[i] == ')'){
                    st.pop();
                }
                else st.push(s[i]);
            }
        }
        if (st.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
