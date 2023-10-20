// 공 던지기
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = numbers[(2*(k-1))%numbers.size()];
    return answer;
}
