// boj 1259 팰린드롬수
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    while(true) {
        cin >> s;
        if (s == "0") {
            break;
        }
        stack<char> st;
        string tmp = "";
        for (int i=0;i<s.size();i++){
            st.push(s[i]);
        }

        while (!st.empty()){
            tmp += st.top();
            st.pop();
        }

        if (tmp == s) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
        
    }
    return 0;
}
