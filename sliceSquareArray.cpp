// 프로그래머스 n^2 배열 자르기
#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    int N = right - left + 1;
    vector<int> answer(N);
    for (int i = 0; i < N; ++i, ++left) {
        answer[i] = (left/n < left%n ? left%n : left/n) + 1;
    }

    return answer;
}
