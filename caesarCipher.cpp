// 프로그래머스 시저 암호
#include <string>
#include <vector>
using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (int i=0;i<s.size();i++){
        if (s[i]==' ') answer += ' ';
        else if (97<=(int)s[i] && (int)s[i]<=122){
            if ((int)s[i]+n>122){
                answer += (char)(96+(int)s[i]+n-122);}
            else answer += (char)((int)s[i]+n);
        }
        else if (65<=(int)s[i] && (int)s[i]<=90) {
            if ((int)s[i]+n>90) {
                answer += (char)(64+(int)s[i]+n-90);
            }
            else answer += (char)((int)s[i]+n);
        
        }
    }
    return answer;
}
