// 프로그래머스 문자열 압축
#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 1001;
    // ex) s: "abcabcabcdefg"
    if (s.size() == 1) return 1;
    for (int i=1;i<s.size()/2+1;i++){ // i: 묶는 개수 
        int text_length = 0;
        string left_string; // 비교할 문자열
        int count = 0; // 비교할 문자열이 중복된 횟수
        for (int j=0;j<s.size();j+=i){ // s를 i 개씩 묶어서 나온 string 의 길이 측정
            if (left_string.empty()) { // 첫번째 문자열은 바로 넣음 -> "abc"
                left_string = s.substr(j,i);
                text_length += i;
            }
            else if (s.substr(j, i) != left_string){
                // 새로운 문자열이 나옴
                if (s.substr(j,i).size() == i){
                    // 현재 문자열을 기억하도록 넣어주고 문자열 길이(i)만큼 더함 -> "3abc"+"def"
                    left_string = s.substr(j,i);
                    count = 0;
                    text_length += i;
                }
                else {
                    // 마지막에 개수가 안 맞아 남는 문자열은 비교 불가 -> 그냥 남은 개수만큼 더해줌 "3abcdef"+"g"
                    text_length += s.substr(j,i).size();
                }
                
            }
            else {
                // 중복되는 경우 count 를 세고 숫자 자리수를 추가
                if (count == 0) text_length += 1; // 첫번째 중복일 때 숫자 한 개 더함 -> "2"+"abc"
                else if (count == 8) text_length += 1; // 9번째 중복일 경우 10의 자리수를 더함
                else if (count == 98) text_length += 1; // 99번째 중복일 경우 100의 자리수를 더함
                else if (count == 998) text_length += 1;// 999번째 중복일 경우 1000의 자리수를 더함
                count += 1;
            }
        }
        if (answer > text_length) answer = text_length; // 모든 결과 중 최소값을 answer에 넣어줌
    }
    return answer;
}
