// boj 7567 그릇
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int answer = 10;
    for (int i=1;i<s.size();i++){
        if (s[i] == s[i-1]) {
            answer += 5;
        }
        else {
            answer += 10;
        }
    }
    cout << answer << "\n";
    return 0;
}
