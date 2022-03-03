// 프로그래머스 카펫
#include <string>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<pair<int,int>> p;
    for (int i=1;i<yellow;i++){
        if (yellow%i==0){
            if (i>yellow/i){
                break;
            }
            p.push_back(make_pair(yellow/i+2, i));
        }
    }
    if (p.empty()) p.push_back(make_pair(3,1));
    for (int i=0;i<p.size();i++){
        if (2*p[i].first + 2*p[i].second == brown){
            answer.push_back(p[i].first);
            answer.push_back(p[i].second+2);
        }
    }
    return answer;
}
