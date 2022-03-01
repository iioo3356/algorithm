// 프로그래머스 구명보트
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int l = 0;
    int r = people.size()-1;
    while (l<=r){
        if (people[l] <= limit-people[r]){
            answer++;
            l++;
            r--;
        }
        else {
            answer++;
            r--;
        }
    }

    return answer;
}
