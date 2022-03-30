// 프로그래머스 삼각 달팽이
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> v;
    // vector<int> zero_element;
    // v.push_back(zero_element);
    for (int i=0;i<n+1;i++){
        vector<int> t(i+1,0);
        v.push_back(t);
    }
    int num = 1;
    int max = n*(n+1)/2;
    int top = 1;
    int bottom = n;
    int left = 1;
    int right = 0;
    int caseNum = 0;

    while (num <= max){
        if (caseNum == 0){                
            for (int i = top; i <= bottom; i++){
                v[i][left] = num;
                num += 1;
            }
            top += 1;
            left += 1;
            caseNum = 1;
        }
        else if (caseNum == 1){
            for (int i = left; i <= bottom - right; i++){
                v[bottom][i] = num;
                num += 1;
            }
            bottom -= 1;
            caseNum = 2;
        }
        else {
            for (int i = bottom; i >= top; i--){
                v[i][i - right] = num;
                num += 1;
            } 
            right += 1;
            top += 1;
            caseNum = 0;
        }
    }
    
    for (int i=1;i<v.size();i++){
        for (int j=1;j<v[i].size();j++){
            answer.push_back(v[i][j]);
        }
    }
    return answer;
}
