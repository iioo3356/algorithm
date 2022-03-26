// 프로그래머스 오픈채팅방
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> um;
    string userId;
    string nickName;
    bool isSpace = false;
    int startIdx = 0;
    for (int i=0;i<record.size();i++){
        if (record[i][0] != 'L') {
            userId = "";
            nickName = "";
            isSpace = false;
            if (record[i][0] == 'E') startIdx = 6;
            else if (record[i][0] == 'C') startIdx = 7;
            for (int j=startIdx;j<record[i].size();j++){
                if (record[i][j] == ' '){
                    isSpace = true;
                    continue;
                }
                if (!isSpace) userId+=record[i][j];
                else nickName += record[i][j];
            }
            um[userId] = nickName; 
        }
    }
    for (int i=0;i<record.size();i++){
        if (record[i][0] != 'C'){
            userId = "";
            for (int j=6;j<record[i].size();j++){
                if (record[i][j] == ' '){
                    break;
                }
                else userId += record[i][j];
            }
        if (record[i][0] == 'E') answer.push_back(um[userId]+"님이 들어왔습니다.");        
        else  answer.push_back(um[userId]+"님이 나갔습니다.");
        }
    }
    return answer;
}
