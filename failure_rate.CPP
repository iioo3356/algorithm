#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> memo;
    int currentStage = 1;
    int parentNum = stages.size();
    int childNum = 0;
    sort(stages.begin(), stages.end());
    for (int i=0; i<stages.size();i++){
        

        if (stages[i] == currentStage){            
            childNum += 1;
            if (i < stages.size()-1){
                continue;  
            }
            else {
                memo.push_back(make_pair(currentStage,(double)childNum/parentNum) );
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
    cout << endl;
    for (int i=0;i<stages.size();i++){
     cout << stages[i] << " ";

    }
    cout << endl;
    for (int i=0;i<memo.size();i++){
        cout << memo[i].first << " " << memo[i].second << endl;
    }
    
    
    
    return answer;
}
