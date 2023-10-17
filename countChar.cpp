// 문자 개수 세기
#include <string>
#include <vector>
using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52, 0);
    for (int i=0;i<my_string.size();i++) {
        if (my_string[i]>='A' && my_string[i]<='Z'){
            answer[my_string[i]-'A'] += 1;
        }
        else {
            answer[my_string[i]-'a'+('Z'-'A'+1)] += 1;
        }
    }
    return answer;
}
