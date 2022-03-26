#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> um;
    vector<string> u_ids;
    for (int i=0;i<record.size();i++){
        if (record[i][0] == 'E'){
            string userId;
            string nickName;
            bool isSpace = false;
            for (int j=6;j<record[i].size();j++){
                if (record[i][j] == ' '){
                    isSpace = true;
                    continue;
                }
                if (!isSpace) userId+=record[i][j];
                else nickName += record[i][j];
            }
            u_ids.push_back(userId);
            um[userId] = nickName;
            cout << userId << endl;
            cout << nickName << endl;
        }
        else if (record[i][0] == 'C'){
            string userId;
            string nickName;
            bool isSpace = false;
            for (int j=7;j<record[i].size();j++){
                if (record[i][j] == ' '){
                    isSpace = true;
                    continue;
                }
                if (!isSpace) userId+=record[i][j];
                else nickName += record[i][j];
            }
            um[userId] = nickName;
            u_ids.push_back(userId);

            cout << userId << endl;
            cout << nickName << endl;
        }
    }
    for (int i=0;i<record.size();i++){
        if (record[i][0] == 'E'){
            string userId;
            for (int j=6;j<record[i].size();j++){
                if (record[i][j] == ' '){
                    break;
                }
                else userId += record[i][j];
            }
            answer.push_back(um[userId]+"님이 들어왔습니다.");
        }
        else if (record[i][0] == 'L'){
            string userId;
            for (int j=6;j<record[i].size();j++){
                if (record[i][j] == ' '){
                    break;
                }
                else userId += record[i][j];
            }
            answer.push_back(um[userId]+"님이 나갔습니다.");
        }

    }
    return answer;
}
