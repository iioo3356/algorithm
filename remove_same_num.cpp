// 프로그래머스 - 같은 숫자는 싫어
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int sameNum = -1;
    for (int i=0;i<arr.size();i++){
        if (sameNum != arr[i]){
            answer.push_back(arr[i]);
            sameNum = arr[i];
        }
        else{
            continue;
        }
    }
    return answer;
}
