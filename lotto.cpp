// 프로그래머스 로또의 최고 순위와 최저 순위
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int correct = 0;
    int zero = 0;
    for (int i=0;i<lottos.size();i++){
        if (lottos[i] == 0) zero += 1;
        else {
            for (int j=0;j<win_nums.size();j++){
                if (lottos[i] == win_nums[j]){
                    correct += 1;
                    break;
                }
            }
        }
    }
    int max_rank = 7 - correct - zero;
    int min_rank = 7 - correct;
    if (max_rank >= 6) {
        answer.push_back(6);
    }
    else {
        answer.push_back(max_rank);
    }
    if (min_rank >= 6) {
        answer.push_back(6);
    }
    else {
        answer.push_back(min_rank);
    }
    return answer;
}
