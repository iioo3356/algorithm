// 프로그래머스 K번째 수
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i=0;i<commands.size();i++){
        int leftIndex = commands[i][0]-1;
        int rightIndex = commands[i][1]-1;
        int findIndex = commands[i][2]-1;
        vector<int> modified = array;
        sort(modified.begin() + leftIndex, modified.begin()+rightIndex+1);
        answer.push_back(*(modified.begin() + leftIndex + findIndex));
    }
    
    return answer;
}
