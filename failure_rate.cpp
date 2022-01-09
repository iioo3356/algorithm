// 프로그래머스 실패율 문제 풀이

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(pair<int, double> a, pair<int, double> b){
    if (a.second == b.second){
        return a.first < b.first;
    }
    else{
        return a.second > b.second;}
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> memo;
    int currentStage = 1;
    int parentNum = stages.size();
    int childNum = 0;
    sort(stages.begin(), stages.end());
    for (int i=stages.back()+1;i<N+1;i++){
        memo.push_back(make_pair(i, 0.0));
    }
    for (int i=0; i<stages.size();i++){
        if (stages[i] == currentStage){            
            childNum += 1;
            if (i < stages.size()-1){
                continue;  
            }
            else {
                memo.push_back(make_pair(currentStage,(double)childNum/parentNum));
                break;
            }
        }        
        memo.push_back(make_pair(currentStage, (double)childNum/parentNum));
        parentNum -= childNum;
        childNum = 1;
        for (int j=currentStage+1;j<stages[i];j++){
            memo.push_back(make_pair(j, 0.0));
        }
        currentStage = stages[i];
        if (currentStage == N+1){
            break;
        }
    }
    sort(memo.begin(), memo.end(), cmp);
    for (int i=0;i<memo.size();i++){
        answer.push_back(memo[i].first);
    }
    
    return answer;
}
