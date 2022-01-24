// 프로그래머스 제일 작은 수 제거하기
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if (arr.size()==1) answer.push_back(-1);
    else {
        int min_bar = INT_MAX;
        int min_idx = 0;
        for (int i=0;i<arr.size();i++){
            if (arr[i]<=min_bar){
                min_bar = arr[i];
                min_idx = i;
            }
        }
        arr.erase(arr.begin()+min_idx);
        answer = arr;
    }
    return answer;
}
