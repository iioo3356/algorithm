// 프로그래머스 주차 요금 계산하기
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<string> carNums;
    unordered_map<string, vector<int>> um;
    for (int i=0;i<records.size();i++){
        int minutes = stoi(records[i].substr(0,2)) * 60 + stoi(records[i].substr(3,2));
        string carNum = records[i].substr(6,4);
        if (um.find(carNum) == um.end()) {
            vector<int> v = {minutes};
            um[carNum] = v;
            carNums.push_back(carNum);

        }
        else {
            um[carNum].push_back(minutes);
        }
    }
    sort(carNums.begin(), carNums.end());
    int sum = 0;
    for (int i=0;i<carNums.size();i++){  
        sum = 0;
        if (um[carNums[i]].size() % 2 == 1) um[carNums[i]].push_back(23*60+59);
        for (int j=0;j<um[carNums[i]].size();j++){
            if (j%2==0) sum -= um[carNums[i]][j];
            else sum += um[carNums[i]][j];
        }
        if (sum <= fees[0]) answer.push_back(fees[1]);
        else answer.push_back(fees[1] + ceil(((double)sum-fees[0])/fees[2])*fees[3]);
    }
    return answer;
}
