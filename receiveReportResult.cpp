// 프로그래머스 신고 결과 받기
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {    
    int memberN = id_list.size();
    vector<int> answer(memberN);
    vector<int> countR(memberN);
    sort(report.begin(), report.end());
    string pastM;
    string pastR;
    for (int i=0;i<report.size();i++){
        size_t space = report[i].find(' ');
        string m = report[i].substr(0,space);
        string r = report[i].substr(space+1);
        if (m == pastM && r == pastR) {
            continue;
        }
        auto idx = find(id_list.begin(), id_list.end(), r);
        countR[idx - id_list.begin()] += 1;
        pastM = m;
        pastR = r;
    }
    pastM = "";
    pastR = "";
    for (int i=0;i<report.size();i++){
        size_t space = report[i].find(' ');
        string m = report[i].substr(0,space);
        string r = report[i].substr(space+1);
        if (m == pastM && r == pastR){
            continue;
        }
        auto idxR = find(id_list.begin(), id_list.end(), r);
        auto idxM = find(id_list.begin(), id_list.end(), m);
        if (countR[idxR - id_list.begin()]>=k)
            answer[idxM - id_list.begin()] += 1;    
        pastM = m;
        pastR = r;
    }
    return answer;
    
}
