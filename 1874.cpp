//boj 1874 스택 수열
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    vector<string> answer;
    for (int i=0;i<n;i++){
        cin >> v[i];
    }
    stack<int> st;
    int idx = 0;
    for (int i=1;i<=n;i++){
        st.push(i);
        answer.push_back("+");

        while (!st.empty()){
            if (st.top() != v[idx]) break;
            else {
                idx++;
                st.pop();
                answer.push_back("-");
            }
        }
    }

    if (!st.empty()) cout << "NO\n";
    else {
        for (int i=0;i<answer.size();i++){
            cout << answer[i] << "\n";
        }
    }
    return 0;
}
