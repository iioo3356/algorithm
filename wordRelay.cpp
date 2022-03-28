// 프로그래머스 영어 끝말잇기
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string, bool> um;
    char lastWord = words[0][words[0].size()-1];
    um[words[0]] = true;
    for (int i=1;i<words.size();i++){
        if (lastWord != words[i][0]) {
            answer.push_back(i);
            break;
        }
        if (um[words[i]] == true) {
            answer.push_back(i);
            break;
        }
        um[words[i]] = true;
        lastWord = words[i][words[i].size()-1];
    }
    if (answer.empty()) answer = {0,0};
    else {
        answer.push_back(answer[0]);
        answer[0] = answer[0] % n + 1;
        answer[1] = answer[1] / n + 1;
    }
    return answer;
}
