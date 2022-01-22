// 프로그래머스 핸드폰 번호 가리기
#include <string>
#include <vector>
using namespace std;

string solution(string phone_number) {
    string last_number = phone_number.substr(phone_number.size()-4, phone_number.size());
    string answer = "";
    for (int i=0;i<phone_number.size()-4;i++){
        answer += "*";
    }
    answer+= last_number;
    return answer;
}
