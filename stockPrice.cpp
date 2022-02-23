// 프로그래머스 주식 가격
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for (int i=0;i<prices.size();i++){
        answer.push_back(0);
        for (int j=i+1;j<prices.size();j++){
            answer[i] += 1;
            if (prices[i] > prices[j]) break;
        }
    }
    return answer;
}
