// 프로그래머스 신규 아이디 추천
#include <string>
#include <iostream>
using namespace std;

string solution(string new_id) {
    string answer = "";
    int point_index = -2;
    for (int i=0;i<new_id.size();i++){
        if (('a'<=new_id[i] && new_id[i]<='z')||('0'<=new_id[i] && new_id[i]<='9')){
            answer += new_id[i];
        }
        else if ('A'<=new_id[i] && new_id[i]<='Z'){
            answer +=tolower(new_id[i]);
        }
        else if (new_id[i]=='.'){
            if (point_index <= int(answer.size()-2)){
                answer += new_id[i];
            }
            point_index = int(answer.size()-1);
        }
        else if (new_id[i] == '-' || new_id[i] == '_'){
            answer += new_id[i];
        }
    }
    while (answer[0]=='.'){
        answer = answer.substr(1, answer.size());
    }
    while (answer[answer.size()-1]=='.'){
        answer = answer.substr(0, answer.size()-1);
    }
    if (answer.size() >=16) {
            answer = answer.substr(0, 15);
            while (answer[answer.size()-1]=='.'){
                answer = answer.substr(0, answer.size()-1);
            }
    }
    if (answer.size() == 0){
        answer = "a";
    }
    while (answer.size() < 3){
        answer += answer[answer.size()-1];
    }
    return answer;
}
