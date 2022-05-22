//BOJ 10828 스택
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    stack<int> st;
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        string cmd;
        int num;
        cin >> cmd;
        if (cmd == "push"){
            cin >> num;
            st.push(num);
        }
        else if (cmd == "pop"){
            if (st.empty()) cout << -1 << endl;
            else {
                cout << st.top() << endl;
                st.pop();
            }
        }
        else if (cmd == "size"){
            cout << st.size() << endl;
        }
        else if (cmd == "empty"){
            cout << st.empty() << endl;
        }
        else {
            if (st.empty()) cout << -1 << endl;
            else cout << st.top() << endl;
        }

    }
    return 0;
}
