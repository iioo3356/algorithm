// 프로그래머스 폰켓몬
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set unique(nums.begin(), nums.end());
    if (nums.size()/2 < unique.size()) answer = nums.size()/2;
    else answer = unique.size();
    return answer;
}
