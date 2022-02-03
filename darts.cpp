// 프로그래머스 카카오 블라인드 채용 1차 다트 게임
#include <string>
#include <vector>
#include <regex>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> numArr = {0,0,0};
    vector<string> rounds;
    regex re("(\\d{1,2}[SDT])[*#]*");
    string round = "";
    smatch r;
    int num = 0;
    while (regex_search(dartResult, r, re)) {
        string match = r.str();
        int roundNum;
        int dIndex = 1;
        if (match[0] == '1' && match[1] == '0'){
            roundNum = 10;
            dIndex += 1;
        }
        else {
            roundNum = match[0]-(int)'0';
        }
        if (match[dIndex] == 'D'){
            roundNum *= roundNum;
        }
        else if (match[dIndex] == 'T'){
            roundNum *= roundNum * roundNum;
        }
        if (match.size() == 3){
            if (match[dIndex+1]=='*'){
                if (num == 0){
                    roundNum *=2;
                }
                else {
                    numArr[num-1] *= 2;
                    roundNum *=2;
                }
            }
            else if (match[dIndex+1]=='#'){
                roundNum *= -1;
            }
        }
        numArr[num] = roundNum;
        num++;
        dartResult= r.suffix();

    }
    answer = numArr[0] + numArr[1] + numArr[2]; 
    return answer;
}
