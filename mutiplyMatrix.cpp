// 프로그래머스 행렬의 곱셈
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for (int i=0;i<arr1.size();i++){
        vector<int> v;
        for (int j=0;j<arr2[0].size();j++){
            v.push_back(0);
        }
        answer.push_back(v);
    }
    
    for (int i=0;i<arr1.size();i++){
        for (int j=0;j<arr2[0].size();j++){
            int s=0;
            for (int k=0;k<arr1[0].size();k++){
                s += arr1[i][k] * arr2[k][j];
            }       
            answer[i][j] = s;

        }
    }
    return answer;
}
