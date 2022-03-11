// 프로그래머스 타겟넘버
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    vector<int> parent;
    parent.push_back(numbers[0]);
    parent.push_back(-numbers[0]);
    for (int i=1;i<numbers.size();i++){
        vector<int> temp;
        for (int j=0;j<parent.size();j++){
            temp.push_back(parent[j] + numbers[i]);
            temp.push_back(parent[j] - numbers[i]);
        }
        parent = temp;
    }
    for (int i=0;i<parent.size();i++){
        if (parent[i] == target) answer+=1;
    }
    return answer;
}
