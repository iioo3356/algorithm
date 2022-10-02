//boj 1550 16진수
#include <iostream>
using namespace std;

int main(){
    long long answer = 0;
    long long hex = 1;

    string s;
    cin >> s;

    for (int i=s.size()-1;i>=0;i--){
        if ('A'<=s[i] && s[i]<='Z'){
            answer += hex*((int)s[i]-55);
        }
        else {
            string t;
            t=s[i];
            answer += hex*stoi(t);
        }
        hex*=16;
    }
    
    cout << answer << "\n";
}
