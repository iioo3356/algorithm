// 프로그래머스 프린터
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<pair<int,int>> pp;
    vector<int> print;
    for (int i=0;i<priorities.size();i++){
        pp.push_back(make_pair(i, priorities[i]));
    }
    while (pp.size()>0){
        pair<int,int> front = pp.front();
        pp.erase(pp.begin());
        bool isAdd = false;
        for (int i=0;i<pp.size();i++){
            if (pp[i].second > front.second){
                pp.push_back(front);
                isAdd = true;
                break;
            }
        }
        if (!isAdd) print.push_back(front.first);
    }
    
    auto idx = find(print.begin(), print.end(), location);
    answer = idx - print.begin() +1;
    
    return answer;
}
