// boj 10799 쇠막대기
#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int answer = 0;
    string s;
    cin >> s;

    stack<int> st;

    for (int i=0;i<s.size();i++){
        if (s[i] == '('){
            st.push(i);
        }
        else {
            if (st.top()+1 == i) {
                // 레이저 앞부분 빼주기
                st.pop();
                answer += st.size();
            }
            else {
                // 막대기 끝 부분 더하기, 막대 없애기
                answer += 1;
                st.pop();
            }
        }
    }

    cout << answer << "\n";
    return 0;
}
