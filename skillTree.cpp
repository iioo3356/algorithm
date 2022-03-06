// 프로그래머스 스킬트리
#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();
    for (int i=0;i<skill_trees.size();i++){
        vector<int> ch(26, 99);
        for (int j=0;j<skill_trees[i].size();j++){
            ch[(int)skill_trees[i][j] - 65 ] = j;
        }
        for (int j=0;j<skill.size()-1;j++){
            if (ch[skill[j]-65] > ch[skill[j+1]-65]){
                answer -= 1;
                break;
            }
        }
    }
    return answer;
}
