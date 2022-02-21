// 프로그래머스 큰 수 만들기
#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer = number;
    int count=0;
    int i=0;
    while (i<answer.size() && count<k){
        if (answer.size() == number.size()-k) break;
        if (answer[i] < answer[i+1]){
            answer.erase(i,1);
            count++;
            i=0;
        }
        else {
            i++;
        }
    }
    if (answer.size() == number.size()-k){
         return answer;
    }
    else {
        return answer.substr(0, number.size()-k);
    }
}
