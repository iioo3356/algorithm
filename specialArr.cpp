// 프로그래머스 특별한 이차원 배열 2
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> arr) {
    int answer = 1;
    for (int i=0;i<arr.size();i++){
        for (int j=0;j<arr.size();j++){
            if (arr[i][j] != arr[j][i]){ 
                answer = 0;
                break;
            }
        }
    }
    return answer;
}
