// 프로그래머스 최고의 집합
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if (s<n) {
        answer.push_back(-1);
    }
    else {
        // 편차가 작아야하고 가장 큰 원소값(몫)이 필요함
        int max_start = s / n;
        int rest = s % n;
        for (int i=0;i<n;i++){
            if (rest > 0) {
                answer.push_back(max_start+1);
                rest--;
            }
            else {
                answer.push_back(max_start);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
