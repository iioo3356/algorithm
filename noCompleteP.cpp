// 프로그래머스 완주하지 못한 선수
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    int j=0;
    for (int i=0; i<completion.size();i++){
        if (completion[i] != participant[i]){
            answer = participant[i];
            break;
        }
        else {        
            j++;
        }
    }
    if (answer == "") answer = participant[j];
    return answer;
}
