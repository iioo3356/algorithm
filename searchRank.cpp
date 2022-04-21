// 프로그래머스 순위 검색
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    unordered_map<string, vector<int>> um;
    
    for (int i=0;i<info.size();i++){
        string tmp_str;
        vector<string> tmp_v;
        for (int j=0;j<info[i].size();j++){
            if (info[i][j] == ' '){
                tmp_v.push_back(tmp_str);
                tmp_str = "";
            }
            else {
                tmp_str += info[i][j];
            }
        }
        tmp_v.push_back(tmp_str);
        for(int j=0; j<16; ++j) { // 비트 마스킹 사용
            string tmp = "";            
            for(int k=0; k<4; ++k) {
                tmp += (j & (1 << k)) ? tmp_v[k] : "-";
            }
            um[tmp].push_back(stoi(tmp_v[4]));
        }
    }
    
    for (auto &iter: um) sort(iter.second.begin(), iter.second.end());
    
    for (int i=0;i<query.size();i++){
        string tmp_str;
        vector<string> tmp_v;        
        int num = 0;

        for (int j=0;j<query[i].size();j++){
            if (query[i][j] == ' '){
                tmp_v.push_back(tmp_str);
                if (tmp_v.size() < 4) j += 4;
                tmp_str = "";
            }
            else {
                tmp_str += query[i][j];
            }
        }
        tmp_v.push_back(tmp_str);
        string q = tmp_v[0] + tmp_v[1] + tmp_v[2] + tmp_v[3];
        vector<int> res = um[q];
        int cnt = res.end() - lower_bound(res.begin(), res.end(), stoi(tmp_v[4]));
        answer.push_back(cnt);
    }
    
    return answer;
}
