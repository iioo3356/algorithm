#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    // 남은 한 변이 가장 긴 경우
    answer += sides[0] + sides[1] - max(sides[0], sides[1]) - 1;
    // 주어진 변 중 하나가 가장 긴 경우
    answer += max(sides[0], sides[1]) - (max(sides[0], sides[1]) - min(sides[0], sides[1]));
    return answer;
}
