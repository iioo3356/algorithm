// boj 1406 에디터
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s; 
    int m;

    cin >> s >> m;
    stack<char> left;
    stack<char> right;

    for (int i=0;i<s.size();i++){
        left.push(s[i]);
    }

    for (int i=0;i<m;i++){
        string c;
        cin >> c;
        if (c == "L"){
            if (!left.empty()){
                right.push(left.top());
                left.pop();
            }
        }
        else if (c == "D") {
            if (!right.empty()){
                left.push(right.top());
                right.pop();
            }
        }
        else if (c == "B") {
            if (!left.empty()) {
                left.pop();
            }
        }
        else if (c == "P"){
            char input;
            cin >> input;
            left.push(input);
        }
    }

    string answer = "";
    while (!left.empty()){
        answer += left.top();
        left.pop();
    }
    reverse(answer.begin(), answer.end());
    while (!right.empty()){
        answer += right.top();
        right.pop();
    }
    cout << answer << "\n";
    return 0;
}
