#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    string origin = "";
    for (int i=0;i<s.size();i++){
        if (s[i]=='z'){
            i+=3;
            origin += "0";
        }
        else if (s[i]=='o'){
            i+=2;
            origin += "1";
        }
        else if (s[i]=='e'){
            i+=4;
            origin += "8";
        }
        else if (s[i]=='n'){
            i+=3;
            origin += "9";
        }
        else if (s[i]=='t'){
            if (s[i+1]=='w'){
                i+=2;
                origin += "2";
            }
            else {
                i+=4;
                origin += "3";
            }
        }
        else if (s[i]=='f'){
            if (s[i+1]=='o'){
                i+=3;
                origin += "4";
            }
            else {
                i+=3;
                origin+="5";
            }
            
        }
        else if (s[i]=='s'){
            cout << "ss" << endl;
            if (s[i+1]=='i'){
                i+=2;
                origin+="6";
            }
            else {
                i+=4;
                origin+="7";
            }
        }
        else{
            origin += s[i];
        }
    }
    answer = stoi(origin);
    return answer;
}
