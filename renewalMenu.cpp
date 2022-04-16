// 프로그래머스 메뉴 리뉴얼
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (int i=0;i<course.size();i++){    
        unordered_map<string, int> um;
        for (int j=0;j<orders.size();j++){
            if (orders[j].size() < course[i]) continue;
            sort(orders[j].begin(), orders[j].end());
            vector<bool> tmp(orders[j].size(), true);
            for (int k=0;k<orders[j].size() - course[i];k++) tmp[k] = false;
            do {
                string s = "";
                for (int k=0;k<tmp.size();k++){
                    if (tmp[k]) s += orders[j][k];
                }
                if (um.find(s) == um.end()) um[s] = 1;
                else um[s] +=1;
                
            } while (next_permutation(tmp.begin(), tmp.end()));
        }
        if (um.empty()) continue;
        vector<pair<string, int>> v(um.begin(), um.end());
        sort(v.begin(), v.end(), cmp);
        if (v[0].second == 1) continue;
        for (int k=0;k<v.size();k++){
            if (v[k].second == v[0].second) answer.push_back(v[k].first);
            else break;
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
