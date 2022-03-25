// 프로그래머스 숫자의 표현
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int nums = 1;
    int sum = 0;
    while (true) {
        sum = 0;
        for (int i=1; i<=nums;i++) sum += i;
        if (sum > n) break;
        if ((n - sum) % (nums++) == 0) answer++;
    }
    return answer;
        
}
