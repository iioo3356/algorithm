// 프로그래머스 땅따먹기
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    for (int i=1;i<land.size();i++){
        int pre_max_idx = max_element(land[i-1].begin(), land[i-1].end()) - land[i-1].begin();
        for (int j=0;j<land[i].size();j++){
            if (pre_max_idx != j) land[i][j] += land[i-1][pre_max_idx];
            else {
                vector<int> tmp = {land[i-1][0], land[i-1][1], land[i-1][2], land[i-1][3]};
                tmp.erase(tmp.begin() + pre_max_idx);
                int second_max_idx = max_element(tmp.begin(), tmp.end()) - tmp.begin();
                land[i][j] += tmp[second_max_idx];
            }
        }
    }
    
    answer = *max_element(land[land.size()-1].begin(), land[land.size()-1].end());

    return answer;
}
