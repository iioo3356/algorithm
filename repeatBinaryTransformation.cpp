// 프로그래머스 이진변환 반복하기
#include <string>
#include <vector>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int zeroNum = 0;
    int round = 0;
    string tmp;
    while(s != "1") {
        tmp = "";
        int size = 0;
        int num;
        round++;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0')
                zeroNum++;
            else
                tmp += "1";
        }
        
        num = tmp.size();
        s = "";
        
        while(num > 0) {
            s += to_string(num % 2);
            num /= 2;
        }
    }
    
    answer.push_back(round);
    answer.push_back(zeroNum);
    return answer;
}
