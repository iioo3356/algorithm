// 프로그래머스 튜플
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp (vector<int> a, vector<int> b){
    return a.size() < b.size();
}
vector<int> solution(string s) {
    vector<vector<int>> v;
    vector<bool> isSame(100001, false);
    vector<int> answer;
    s = s.substr(1, s.size()-2);
    vector<int> tmp;
    string n;
    for (int i=0; i<s.size();i++){
        if (s[i] == '{'){
            vector<int> tmp2;
            tmp = tmp2;
        }
        else if (s[i] == '}'){
            v.push_back(tmp);
        }
        else if (s[i]>='0' && s[i]<='9'){
            n += s[i];
            if (s[i+1] == ',' || s[i+1] == '}'){
                tmp.push_back(stoi(n));
                n = "";
            }
        }
    }
    sort(v.begin(), v.end(), cmp);
    for (int i=0;i<v.size();i++){
        for (int j=0;j<v[i].size();j++){
            if (!isSame[v[i][j]]){
                answer.push_back(v[i][j]);
                isSame[v[i][j]] = true;
            }
        }
    }
	return answer;
}
