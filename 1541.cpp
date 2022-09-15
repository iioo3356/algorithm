//boj 1541 잃어버린 괄호
#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int answer = 0;
    int flag = 1;
    string num = "";
    for (int i=0;i<s.size();i++){
        if (s[i] == '-' || s[i] == '+'){
            answer += flag * stoi(num);
            num = "";
            if (s[i] == '-') {
                flag = -1;       
            }
        }
        else {
            num += s[i];
        }
    }
    answer += flag * stoi(num);
    cout << answer;
    return 0;
}
