// 프로그래머스 쿼드압축 후 개수 세기
#include <string>
#include <vector>

using namespace std;

vector<int> c;
void quadCompress(vector<vector<int>> v) {
    if (v.size() == 1) {
        c.push_back(v[0][0]);
        return;
    }
    int sum = 0;
    vector<vector<int>> tmp1(v.size()/2, vector<int> (v.size()/2, 0));
    vector<vector<int>> tmp2(v.size()/2, vector<int> (v.size()/2, 0));
    vector<vector<int>> tmp3(v.size()/2, vector<int> (v.size()/2, 0));
    vector<vector<int>> tmp4(v.size()/2, vector<int> (v.size()/2, 0));
    
    for (int i=0;i<v.size();i++){
        for (int j=0;j<v[i].size();j++){
            sum += v[i][j];
            if (i < v.size()/2 && j < v.size()/2) tmp1[i][j] = v[i][j];
            else if (i < v.size()/2 && j >=v.size()/2) tmp2[i][j-v.size()/2] = v[i][j];
            else if (i >= v.size()/2 && j < v.size()/2) tmp3[i-v.size()/2][j] = v[i][j];
            if (i >= v.size()/2 && j >= v.size()/2) tmp4[i-v.size()/2][j-v.size()/2] = v[i][j];
        }
    }
    if (sum == 0) {
        c.push_back(0);
        return;
    }
    else if (sum == v.size() * v.size()){
        c.push_back(1);
        return;
    }
    else {
        quadCompress(tmp1);
        quadCompress(tmp2);
        quadCompress(tmp3);
        quadCompress(tmp4);
    }
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2,0);
    quadCompress(arr);
    for (int i=0;i<c.size();i++){
        if (c[i] == 0) answer[0]++;
        else answer[1]++;
    }
    
    return answer;
}
