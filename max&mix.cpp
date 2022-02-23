// 프로그래머스 최댓값과 최솟값
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    string s_num = "";
    vector<int> v;
    for (int i=0;i<s.size();i++){
        if (s[i] == ' '){
            v.push_back(stoi(s_num));
            s_num = "";
        }
        s_num += s[i];
    }
    v.push_back(stoi(s_num));
    sort(v.begin(), v.end());
    answer += to_string(v[0]);
    answer += " ";
    answer += to_string(v[v.size()-1]);
    return answer;
}
